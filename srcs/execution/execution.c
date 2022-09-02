/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/02 15:44:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <unistd.h>

void	close_all_pipes(t_prg_data *prg_data)
{
	int	i;

	i = 0;
	while (i < prg_data->nb_commands)
	{
		if (prg_data->commands[i].pipe_out[0] != -1)
			close(prg_data->commands[i].pipe_out[0]);
		if (prg_data->commands[i].pipe_out[1] != -1)
			close(prg_data->commands[i].pipe_out[1]);
		i++;
	}
}

int	create_pipes(t_prg_data *prg_data)
{
	int	i;
	int	fds_pipe[2];

	i = 0;
	while (i < prg_data->nb_commands - 1)
	{
		if (pipe(fds_pipe) == -1)
		{
			ft_perror_errno(*prg_data);
			close_all_pipes(prg_data);
			return (0);
		}
		prg_data->commands[i].pipe_out[0] = fds_pipe[0];
		prg_data->commands[i].pipe_out[1] = fds_pipe[1];
		prg_data->commands[i + 1].pipe_in[0] = fds_pipe[0];
		prg_data->commands[i + 1].pipe_in[1] = fds_pipe[1];
		i++;
	}
	return (1);
}

int	execute(t_prg_data *prg_data)
{
	if (!create_pipes(prg_data))
		return (0);
	return (1);
}
