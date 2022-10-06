/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/06 02:31:14 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "unistd.h"

int	exit_execution(t_prg_data *prg_data)
{
	close_all_pipes(prg_data);
	free(prg_data->commands);
	free(prg_data->commands_pids);
	return (0);
}

void	exec_command(t_prg_data	*prg_data, t_command *command)
{
	(void)prg_data;
	(void)command;
}

int	launch_processes(t_prg_data *prg_data)
{
	int	i;

	prg_data->commands_pids = malloc(sizeof(int) * prg_data->nb_commands);
	if (!prg_data->commands_pids)
		return (0);
	i = 0;
	while (i < prg_data->nb_commands)
	{
		prg_data->commands_pids[i] = fork();
		if (prg_data->commands_pids < 0)
			return (0);
		if (prg_data->commands_pids[i] == 0)
		{
			exec_command(prg_data, &prg_data->commands[i]);
			break ;
		}
		i++;
	}
	return (1);
}

int	execute(t_prg_data *prg_data)
{
	prg_data->commands_pids = 0;
	if (!create_pipes(prg_data))
		return (exit_execution(prg_data));
	if (!launch_processes(prg_data))
		return (exit_execution(prg_data));
	return (1);
}
