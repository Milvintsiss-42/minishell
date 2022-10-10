/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:10:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/10 21:15:42 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// This execution is not protected as it is only used for debugging purposes
// ls | cat | wc -l
void	test_execution(t_prg_data *prg_data)
{
	prg_data->nb_commands = 3;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[1] = default_command();
	prg_data->commands[2] = default_command();
	prg_data->commands[0].env = prg_data->env;
	prg_data->commands[1].env = prg_data->env;
	prg_data->commands[2].env = prg_data->env;
	prg_data->commands[0].cmd = "ls";
	prg_data->commands[1].cmd = "cat";
	prg_data->commands[2].cmd = "wc";
	prg_data->commands[0].args = malloc(sizeof(char *) * 2);
	prg_data->commands[1].args = malloc(sizeof(char *) * 2);
	prg_data->commands[2].args = malloc(sizeof(char *) * 3);
	prg_data->commands[0].args[0] = prg_data->commands[0].cmd;
	prg_data->commands[1].args[0] = prg_data->commands[1].cmd;
	prg_data->commands[2].args[0] = prg_data->commands[2].cmd;
	prg_data->commands[2].args[1] = "-l";
	prg_data->commands[2].is_last = 1;
	execute(prg_data);
}
