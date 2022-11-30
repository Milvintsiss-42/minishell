/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:07:11 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 11:41:08 by ple-stra         ###   ########.fr       */
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
