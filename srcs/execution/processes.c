/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:13:36 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/11 16:40:14 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <sys/wait.h>

static void	exit_process(t_prg_data *prg_data, int err)
{
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
		exit_process(prg_data, s_errno);
	}
	execve(abs_path, command->args, command->env);
	exit_process(prg_data, ft_perror_errno(*prg_data));
}

static void	launch_child(t_prg_data	*prg_data, t_command *command)
{
	exec_command(prg_data, command);
}

int	launch_childs(t_prg_data *prg_data)
{
	int	i;

	prg_data->commands_pids = malloc(sizeof(int) * prg_data->nb_commands);
	if (!prg_data->commands_pids)
		return (ft_perror_errno(*prg_data) * 0);
	i = 0;
	while (i < prg_data->nb_commands)
	{
		prg_data->commands_pids[i] = fork();
		if (prg_data->commands_pids < 0)
			return (ft_perror_errno(*prg_data) * 0);
		if (prg_data->commands_pids[i] == 0)
		{
			launch_child(prg_data, &prg_data->commands[i]);
			break ;
		}
		i++;
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
		if (waitpid(prg_data->commands_pids[i], &wstatus, 0) == -1)
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
