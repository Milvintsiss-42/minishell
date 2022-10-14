/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/14 19:43:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "unistd.h"

int	clean_execution(t_prg_data *prg_data)
{
	close_here_docs_pipes(prg_data);
	reset_commands_data_and_free(prg_data);
	return (0);
}

static int	create_and_cpy_last_pipe(t_prg_data *prg_data, int index)
{
	if (index != 0)
		cpy_pipe(prg_data->commands[index].pipe_in,
			prg_data->commands[index - 1].pipe_out);
	if (index != prg_data->nb_commands - 1)
		if (pipe(prg_data->commands[index].pipe_out) == -1)
			return (ft_perror_errno(*prg_data) * 0);
	return (1);
}

static void	close_stdin_pipes(t_command *command, int is_first_command)
{
	if (command->e_stdin == stream_HERE_DOC)
		close_pipe(command->here_doc_pipe);
	if (!is_first_command)
		close_pipe(command->pipe_in);
}

static int	launch_childs_or_builtin(t_prg_data *prg_data)
{
	int	i;

	i = -1;
	while (++i < prg_data->nb_commands)
	{
		// TODO: redirections and pipes for echo, pwd, etc
		if (!create_and_cpy_last_pipe(prg_data, i))
			return (0);
		if (is_builtin(&prg_data->commands[i]))
			exec_builtin(prg_data, &prg_data->commands[i]);
		else
		{
			prg_data->commands[i].pid = fork();
			if (prg_data->commands[i].pid < 0)
				return (ft_perror_errno(*prg_data) * 0);
			if (prg_data->commands[i].pid == 0)
			{
				launch_child(prg_data, &prg_data->commands[i]);
				break ;
			}
		}
		close_stdin_pipes(&prg_data->commands[i], i == 0);
	}
	return (1);
}

// If something fails during the execution of this method or the last child
// quitted unexpectedly, returns -1.
// Otherwise the returns result of the last child is returned.
int	execute(t_prg_data *prg_data)
{
	int	return_result;

	set_streams_enums(prg_data);
	if (!prompt_here_docs(prg_data))
		return (clean_execution(prg_data));
	if (!launch_childs_or_builtin(prg_data))
		return (clean_execution(prg_data));
	return_result = wait_for_childs_to_finish(prg_data);
	clean_execution(prg_data);
	return (return_result);
}
