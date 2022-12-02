/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:07:11 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/02 21:22:49 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// Returns 0 in case of success, returns errno otherwise
int	set_here_doc_as_stdin(t_prg_data *prg_data, t_command *command)
{
	close(command->here_doc_pipe[1]);
	if (dup2(command->here_doc_pipe[0], STDIN_FILENO) == -1)
	{
		close(command->here_doc_pipe[0]);
		return (ft_perror_errno(*prg_data));
	}
	close(command->here_doc_pipe[0]);
	return (0);
}

void	close_here_docs_pipes(t_prg_data *prg_data)
{
	int	i;

	i = -1;
	while (++i < prg_data->nb_commands)
	{
		close_pipe(prg_data->commands[i].here_doc_pipe);
	}
}

static t_bool	expand_heredoc(t_command *command)
{
	t_bool	ret;

	if (!command->here_doc_limiter || !command->here_doc_limiter[0])
		return (FALSE);
	ret = TRUE;
	while (*command->here_doc_limiter)
	{
		if (*command->here_doc_limiter == '"'
			|| *command->here_doc_limiter == '\'')
			ret = FALSE;
		command->here_doc_limiter++;
	}
	return (ret);
}

int	delete_quotes_heredoc(t_prg_data *prg_data)
{
	char	*save;
	int		i;

	i = -1;
	while (++i < prg_data->nb_commands)
	{
		if ((&prg_data->commands[i])->here_doc_limiter)
		{
			prg_data->commands[i].expand_here_doc = expand_heredoc(
					&prg_data->commands[i]);
			save = (&prg_data->commands[i])->here_doc_limiter;
			(&prg_data->commands[i])->here_doc_limiter
				= expand_env_variables_in_arg(prg_data,
					(&prg_data->commands[i])->here_doc_limiter, TRUE);
			free(save);
			if (!(&prg_data->commands[i])->here_doc_limiter)
				return (0);
		}
	}
	return (1);
}
