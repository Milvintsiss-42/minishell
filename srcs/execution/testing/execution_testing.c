/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:10:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/14 19:24:31 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	test_execution_second_pipeline(t_prg_data *prg_data)
{
	prg_data->nb_commands = 3;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = default_command();
	prg_data->commands[0].env = prg_data->env;
	prg_data->commands[0].cmd = ft_strdup("cd");
	prg_data->commands[0].args = malloc(sizeof(char *) * 3);
	prg_data->commands[0].args[0] = ft_strdup(prg_data->commands[0].cmd);
	prg_data->commands[0].args[1] = ft_strdup("includes");
	prg_data->commands[0].args[2] = 0;
	prg_data->commands[1] = default_command();
	prg_data->commands[1].env = prg_data->env;
	prg_data->commands[1].cmd = ft_strdup("pwd");
	prg_data->commands[1].args = malloc(sizeof(char *) * 2);
	prg_data->commands[1].args[0] = ft_strdup(prg_data->commands[1].cmd);
	prg_data->commands[1].args[1] = 0;
	prg_data->commands[2] = default_command();
	prg_data->commands[2].env = prg_data->env;
	prg_data->commands[2].cmd = ft_strdup("cat");
	prg_data->commands[2].args = malloc(sizeof(char *) * 3);
	prg_data->commands[2].args[0] = ft_strdup(prg_data->commands[2].cmd);
	prg_data->commands[2].args[1] = ft_strdup("-e");
	prg_data->commands[2].args[2] = 0;
	prg_data->commands[2].is_last = 1;
	return (execute(prg_data));
}

static int	test_execution_third_pipeline(t_prg_data *prg_data)
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

// This execution is not protected as it is only used for debugging purposes
// cat << HERE > outfile | echo "hello world" | cat < infile | cat <<HERE2
// cd "includes" | pwd
int	test_execution(t_prg_data *prg_data)
{
	test_execution_first_pipeline(prg_data);
	test_execution_second_pipeline(prg_data);
	return (test_execution_third_pipeline(prg_data));
}
