/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing_third_pipeline.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:59:12 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/26 01:19:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	test_execution_third_pipeline(t_prg_data *prg_data)
{
	prg_data->nb_commands = 3;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[0].args = malloc(sizeof(char *) * 3);
	prg_data->commands[0].args[0] = ft_strdup("cd");
	prg_data->commands[0].args[1] = ft_strdup("includes");
	prg_data->commands[0].args[2] = 0;
	prg_data->commands[1] = default_command();
	prg_data->commands[1].args = malloc(sizeof(char *) * 2);
	prg_data->commands[1].args[0] = ft_strdup("pwd");
	prg_data->commands[1].args[1] = 0;
	prg_data->commands[2] = default_command();
	prg_data->commands[2].args = malloc(sizeof(char *) * 3);
	prg_data->commands[2].args[0] = ft_strdup("cat");
	prg_data->commands[2].args[1] = ft_strdup("-e");
	prg_data->commands[2].args[2] = 0;
	return (execute(prg_data));
}
