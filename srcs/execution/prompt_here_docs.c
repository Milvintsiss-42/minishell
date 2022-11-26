/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_here_docs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:43:08 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/26 01:14:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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

static int	handle_errors(t_prg_data *prg_data, t_command *command, char *line,
	int lines_count)
{
	if (errno != 0 && errno != 22)
		return (ft_perror_errno(*prg_data) * 0);
	if (!line)
		ft_printf_fd(STDERR_FILENO, ERR_CSM_EOF_IN_HERE_DOC,
			prg_data->bin_name, lines_count, command->here_doc_limiter);
	return (1);
}

// TODO: Handle signals
static int	prompt_here_doc(t_prg_data *prg_data, t_command *command)
{
	char	*line;
	size_t	len;
	int		lines_count;

	lines_count = 0;
	if (pipe(command->here_doc_pipe) == -1)
		return (ft_perror_errno(*prg_data) * 0);
	while (1)
	{
		ft_printf("%s> ", command->args[0]);
		line = get_next_line(STDIN_FILENO);
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
	if (!handle_errors(prg_data, command, line, lines_count))
		return (0);
	return (1);
}

int	prompt_here_docs(t_prg_data *prg_data)
{
	int	i;

	i = -1;
	while (++i < prg_data->nb_commands)
		if (prg_data->commands[i].e_stdin == stream_HERE_DOC
			&& !prompt_here_doc(prg_data, &prg_data->commands[i]))
			return (0);
	return (1);
}
