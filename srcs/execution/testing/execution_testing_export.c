/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing_export.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 02:38:38 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/14 02:57:53 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	test_execution_export(t_prg_data *prg_data)
{
	prg_data->nb_commands = 1;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[0].cmd = ft_strdup("export");
	prg_data->commands[0].args = malloc(sizeof(char *) * 8);
	prg_data->commands[0].args[0] = ft_strdup(prg_data->commands[0].cmd);
	prg_data->commands[0].args[1] = ft_strdup("new=");
	prg_data->commands[0].args[2] = ft_strdup("new2=a");
	prg_data->commands[0].args[3] = ft_strdup("dontaddthis");
	prg_data->commands[0].args[4] = ft_strdup("new3==hello equal sign");
	prg_data->commands[0].args[5] = ft_strdup("=i'm empty bitch");
	prg_data->commands[0].args[6] = ft_strdup("new 5=and an invalid one");
	prg_data->commands[0].args[7] = 0;
	prg_data->commands[0].is_last = 1;
	return (execute(prg_data));
}
