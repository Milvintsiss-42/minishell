/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:07:18 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/20 11:12:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	test_execution_env(t_prg_data *prg_data)
{
	prg_data->nb_commands = 1;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[0].cmd = ft_strdup("env");
	prg_data->commands[0].args = malloc(sizeof(char *) * 2);
	prg_data->commands[0].args[0] = ft_strdup(prg_data->commands[0].cmd);
	prg_data->commands[0].args[1] = 0;
	return (execute(prg_data));
}
