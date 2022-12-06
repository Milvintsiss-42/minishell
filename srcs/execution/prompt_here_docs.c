/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_here_docs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:43:08 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/06 17:01:02 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "signals.h"

static int	is_end_of_input(t_command *command, char *line, size_t len)
{
	int	is_end_of_input;

	*(line + len - 1) = 0;
	is_end_of_input = (((*command->here_doc_limiter != 0) ^ (len == 1))
			&& ft_strncmp(line, command->here_doc_limiter,
				ft_strlen(command->here_doc_limiter) + 1) == 0);
	*(line + len - 1) = '\n';
	return (is_end_of_input);
}

// Returns 0 on success, errno otherwise
static int	handle_errors(t_prg_data *prg_data, t_command *command, char *line,
	int lines_count)
{
	if (errno != 0 && errno != 22 && g_last_exit_status != -42)
		return (ft_perror_errno(*prg_data));
	if (!line && errno == 0)
		ft_printf_fd(STDERR_FILENO, ERR_CSM_EOF_IN_HERE_DOC,
			prg_data->bin_name, lines_count, command->here_doc_limiter);
	return (0);
}

// Returns 0 on success, errno otherwise
static int	prompt_here_doc(t_prg_data *prg_data, t_command *command)
{
	char	*line;
	size_t	len;
	int		lines_count;

	lines_count = 0;
	if (pipe(command->here_doc_pipe) == -1)
		return (ft_perror_errno(*prg_data));
	while (1)
	{
		if (command->args)
			ft_printf("%s> ", command->args[0]);
		line = get_next_heredoc_line(prg_data, command);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (is_end_of_input(command, line, len))
			break ;
		write(command->here_doc_pipe[1], line, len);
		lines_count++;
		free(line);
	}
	free(line);
	get_next_line(STDIN_FILENO, 1);
	if (handle_errors(prg_data, command, line, lines_count) != 0)
		return (errno);
	return (0);
}

static int	on_sigint(int save_stdin)
{
	g_last_exit_status = 130;
	dup2(save_stdin, STDIN_FILENO);
	write(1, "\n", 1);
	return (130);
}

// Returns 0 on success, errno otherwise
int	prompt_here_docs(t_prg_data *prg_data)
{
	int	i;
	int	save_stdin;

	i = -1;
	save_stdin = dup(STDIN_FILENO);
	if (save_stdin == -1)
		return (ft_perror_errno(*prg_data));
	ft_signal_handler_heredoc();
	while (++i < prg_data->nb_commands)
	{
		if (prg_data->commands[i].e_stdin == stream_HERE_DOC)
		{
			if (prompt_here_doc(prg_data, &prg_data->commands[i]) != 0)
			{
				close(save_stdin);
				return (errno);
			}
			if (g_last_exit_status == -42)
				return (on_sigint(save_stdin));
		}
	}
	close(save_stdin);
	ft_signal_handler_ignore();
	return (0);
}
