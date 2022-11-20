/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing_first_pipeline.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:22:07 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/20 11:12:05 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_command	test_command1(void)
{
	t_command	command;

	command = default_command();
	command.cmd = ft_strdup("cat");
	command.args = malloc(sizeof(char *) * 2);
	command.args[0] = ft_strdup(command.cmd);
	command.args[1] = 0;
	command.outfile = ft_strdup("outfile");
	command.here_doc_limiter = ft_strdup("HERE");
	return (command);
}

static t_command	test_command2(void)
{
	t_command	command;

	command = default_command();
	command.cmd = ft_strdup("echo");
	command.args = malloc(sizeof(char *) * 3);
	command.args[0] = ft_strdup(command.cmd);
	command.args[1] = ft_strdup("hello world");
	command.args[2] = 0;
	return (command);
}

static t_command	test_command3(void)
{
	t_command	command;

	command = default_command();
	command.cmd = ft_strdup("cat");
	command.args = malloc(sizeof(char *) * 2);
	command.args[0] = ft_strdup(command.cmd);
	command.args[1] = 0;
	command.infile = ft_strdup("infile");
	return (command);
}

static t_command	test_command4(void)
{
	t_command	command;

	command = default_command();
	command.cmd = ft_strdup("cat");
	command.args = malloc(sizeof(char *) * 2);
	command.args[0] = ft_strdup(command.cmd);
	command.args[1] = 0;
	command.here_doc_limiter = ft_strdup("HERE2");
	return (command);
}

int	test_execution_first_pipeline(t_prg_data *prg_data)
{
	prg_data->nb_commands = 4;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = test_command1();
	prg_data->commands[1] = test_command2();
	prg_data->commands[2] = test_command3();
	prg_data->commands[3] = test_command4();
	return (execute(prg_data));
}
