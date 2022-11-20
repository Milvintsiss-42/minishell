/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing_sixth_pipeline.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:02:36 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/20 11:12:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	test_execution_sixth_pipeline(t_prg_data *prg_data)
{
	prg_data->nb_commands = 1;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[0].cmd = ft_strdup("echo");
	prg_data->commands[0].args = malloc(sizeof(char *) * 5);
	prg_data->commands[0].args[0] = ft_strdup(prg_data->commands[0].cmd);
	prg_data->commands[0].args[1] = ft_strdup("-n");
	prg_data->commands[0].args[2] = ft_strdup("hello");
	prg_data->commands[0].args[3] = ft_strdup("world");
	prg_data->commands[0].args[4] = 0;
	return (execute(prg_data));
}
