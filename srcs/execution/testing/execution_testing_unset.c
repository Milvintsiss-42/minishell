/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing_unset.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:44:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/19 03:05:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	test_execution_unset(t_prg_data *prg_data)
{
	prg_data->nb_commands = 1;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[0].cmd = ft_strdup("unset");
	prg_data->commands[0].args = malloc(sizeof(char *) * 9);
	prg_data->commands[0].args[0] = ft_strdup(prg_data->commands[0].cmd);
	prg_data->commands[0].args[1] = ft_strdup("PATH");
	prg_data->commands[0].args[2] = ft_strdup("this one incorrect");
	prg_data->commands[0].args[3] = ft_strdup("also=");
	prg_data->commands[0].args[4] = ft_strdup(" new3");
	prg_data->commands[0].args[5] = ft_strdup("dont_exist");
	prg_data->commands[0].args[6] = ft_strdup("incorrect_character#");
	prg_data->commands[0].args[7] = ft_strdup("last");
	prg_data->commands[0].args[8] = 0;
	prg_data->commands[0].is_last = 1;
	return (execute(prg_data));
}
