/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:13:36 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/13 22:04:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/wait.h>

void	exit_process(t_prg_data *prg_data, t_command *command, int err)
{
	close_pipe(command->pipe_in);
	close_pipe(command->pipe_out);
	clean_execution(prg_data);
	exit(err);
}

static void	exec_command(t_prg_data *prg_data, t_command *command)
{
	char	*abs_path;
	int		s_errno;

	s_errno = get_absolute_path(&abs_path, command->cmd,
			get_path_from_env(command->env));
	if (!abs_path)
	{
		if (s_errno == 2)
		{
			s_errno = 127;
			ft_fperror(*prg_data, command->cmd, ERR_CMD_NOT_FOUND);
		}
		else
			ft_fperror(*prg_data, command->cmd, strerror(s_errno));
		exit_process(prg_data, command, s_errno);
	}
	execve(abs_path, command->args, command->env);
	exit_process(prg_data, command, ft_perror_errno(*prg_data));
}

static void	launch_child(t_prg_data	*prg_data, t_command *command)
{
	if (command->e_stdin == stream_HERE_DOC)
		set_here_doc_as_stdin(prg_data, command);
	else if (command->e_stdin == stream_REDIR)
		set_infile_as_stdin(prg_data, command);
	else if (command->e_stdin == stream_PIPE)
		sets_pipe_as_stdin(prg_data, command);
	close_pipe(command->pipe_in);
	if (command->e_stdout == stream_REDIR)
		set_outfile_as_stdout(prg_data, command);
	else if (command->e_stdout == stream_PIPE)
		sets_pipe_as_stdout(prg_data, command);
	close_pipe(command->pipe_out);
	exec_command(prg_data, command);
}

int	launch_childs(t_prg_data *prg_data)
{
	int	i;

	i = -1;
	while (++i < prg_data->nb_commands)
	{
		// TODO: redirections and pipes for echo, pwd, etc
		if (is_builtin(&prg_data->commands[i]))
		{
			exec_builtin(prg_data, &prg_data->commands[i]);
			continue ;
		}
		if (i != 0)
			cpy_pipe(prg_data->commands[i].pipe_in,
				prg_data->commands[i - 1].pipe_out);
		if (i != prg_data->nb_commands - 1)
			if (pipe(prg_data->commands[i].pipe_out) == -1)
				return (ft_perror_errno(*prg_data) * 0);
		prg_data->commands[i].pid = fork();
		if (prg_data->commands[i].pid < 0)
			return (ft_perror_errno(*prg_data) * 0);
		if (prg_data->commands[i].pid == 0)
		{
			launch_child(prg_data, &prg_data->commands[i]);
			break ;
		}
		if (prg_data->commands[i].e_stdin == stream_HERE_DOC)
			close_pipe(prg_data->commands[i].here_doc_pipe);
		if (i != 0)
			close_pipe(prg_data->commands[i].pipe_in);
	}
	return (1);
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
	while (++i < prg_data->nb_commands - 1)
	{
		if (is_builtin(&prg_data->commands[i]))
			continue ;
		if (waitpid(prg_data->commands[i].pid, &wstatus, 0) == -1)
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
