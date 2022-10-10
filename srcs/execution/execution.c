/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/10 21:30:58 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "unistd.h"

int	clean_execution(t_prg_data *prg_data)
{
	close_all_pipes(prg_data);
	// TODO: method to free all command struct
	free(prg_data->commands);
	free(prg_data->commands_pids);
	return (0);
}

int	execute(t_prg_data *prg_data)
{
	prg_data->commands_pids = 0;
	if (!create_pipes(prg_data))
		return (clean_execution(prg_data));
	if (!launch_childs(prg_data))
		return (clean_execution(prg_data));
	clean_execution(prg_data);
	// TODO: should return the result of the last command
	return (1);
}
