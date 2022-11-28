/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:13:36 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/28 18:51:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/wait.h>

void	exit_process(t_prg_data *prg_data, t_command *command, int err)
{
	close_pipe(command->pipe_in);
	close_pipe(command->pipe_out);
	clean_execution(prg_data);
	clear_prg_data(prg_data);
	exit(err);
}

static void	exec_command(t_prg_data *prg_data, t_command *command)
{
	char	*abs_path;
	int		s_errno;

	s_errno = get_absolute_path(&abs_path, command->args[0],
			get_path_from_env(prg_data->env));
	if (!abs_path)
	{
		if (s_errno == 2)
		{
			s_errno = 127;
			ft_fperror(*prg_data, command->args[0], ERR_CMD_NOT_FOUND);
		}
		else
			ft_fperror(*prg_data, command->args[0], strerror(s_errno));
		exit_process(prg_data, command, s_errno);
	}
	execve(abs_path, command->args, prg_data->env);
	exit_process(prg_data, command,
		ft_fperror_errno(*prg_data, command->args[0]));
}

void	launch_child(t_prg_data	*prg_data, t_command *command)
{
	int	err;

	err = 0;
	if (command->e_stdin == stream_HERE_DOC)
		err = set_here_doc_as_stdin(prg_data, command);
	else if (command->e_stdin == stream_REDIR)
		err = set_infile_as_stdin(prg_data, command);
	else if (command->e_stdin == stream_PIPE)
		err = sets_pipe_as_stdin(prg_data, command);
	close_pipe(command->pipe_in);
	if (err != 0)
		exit_process(prg_data, command, err);
	if (command->e_stdout == stream_REDIR)
		err = set_outfile_as_stdout(prg_data, command);
	else if (command->e_stdout == stream_PIPE)
		err = sets_pipe_as_stdout(prg_data, command);
	close_pipe(command->pipe_out);
	if (err != 0)
		exit_process(prg_data, command, err);
	if (is_builtin(command))
		exec_builtin(prg_data, command, 1);
	else
		exec_command(prg_data, command);
}

// Wait for all childs to finish, gets the return result of the last child and
// returns it.
// If something fails during the execution of this method or the last child
// quitted unexpectedly, returns -1.
int	wait_for_childs_to_finish(t_prg_data *prg_data)
{
	int	i;
	int	wstatus;
	int	err;

	i = -1;
	err = 0;
	while (++i < prg_data->nb_cmds_in_pl)
	{
		if (waitpid(prg_data->cur_pipeline[i].pid, &wstatus, 0) == -1)
		{
			ft_perror_errno(*prg_data);
			err = 1;
		}
	}
	if (err)
		return (-1);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (-1);
}
