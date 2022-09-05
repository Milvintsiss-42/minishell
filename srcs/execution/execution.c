/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/05 21:38:45 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "unistd.h"

int	exit_execution(t_prg_data *prg_data)
{
	close_all_pipes(prg_data);
	free(prg_data->commands);
	return (0);
}

int	execute(t_prg_data *prg_data)
{
	if (!create_pipes(prg_data))
		return (exit_execution(prg_data));
	return (1);
}
