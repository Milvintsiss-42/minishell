/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing_second_pipeline.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:58:41 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/07 16:59:19 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	test_execution_second_pipeline(t_prg_data *prg_data)
{
	prg_data->nb_commands = 2;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[0].env = prg_data->env;
	prg_data->commands[0].cmd = ft_strdup("ls");
	prg_data->commands[0].args = malloc(sizeof(char *) * 3);
	prg_data->commands[0].args[0] = ft_strdup(prg_data->commands[0].cmd);
	prg_data->commands[0].args[1] = ft_strdup("-la");
	prg_data->commands[0].args[2] = 0;
	prg_data->commands[1] = default_command();
	prg_data->commands[1].env = prg_data->env;
	prg_data->commands[1].cmd = ft_strdup("cat");
	prg_data->commands[1].args = malloc(sizeof(char *) * 3);
	prg_data->commands[1].args[0] = ft_strdup(prg_data->commands[1].cmd);
	prg_data->commands[1].args[1] = ft_strdup("-e");
	prg_data->commands[1].args[2] = 0;
	prg_data->commands[1].is_last = 1;
	return (execute(prg_data));
}
