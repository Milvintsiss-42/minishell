/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:10:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/13 16:56:28 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_command	test_command1(t_prg_data *prg_data)
{
	t_command	command;

	command = default_command();
	command.env = prg_data->env;
	command.cmd = ft_strdup("cat");
	command.args = malloc(sizeof(char *) * 2);
	command.args[0] = ft_strdup(command.cmd);
	command.args[1] = 0;
	command.outfile = ft_strdup("outfile");
	command.here_doc_limiter = ft_strdup("HERE");
	return (command);
}

static t_command	test_command2(t_prg_data *prg_data)
{
	t_command	command;

	command = default_command();
	command.env = prg_data->env;
	command.cmd = ft_strdup("echo");
	command.args = malloc(sizeof(char *) * 3);
	command.args[0] = ft_strdup(command.cmd);
	command.args[1] = ft_strdup("hello world");
	command.args[2] = 0;
	return (command);
}

static t_command	test_command3(t_prg_data *prg_data)
{
	t_command	command;

	command = default_command();
	command.env = prg_data->env;
	command.cmd = ft_strdup("cat");
	command.args = malloc(sizeof(char *) * 2);
	command.args[0] = ft_strdup(command.cmd);
	command.args[1] = 0;
	command.infile = ft_strdup("infile");
	command.is_last = 1;
	return (command);
}

// This execution is not protected as it is only used for debugging purposes
// cat << HERE > outfile | echo "hello world" | cat < infile
int	test_execution(t_prg_data *prg_data)
{
	prg_data->nb_commands = 3;
	prg_data->commands = malloc(sizeof(t_command) * prg_data->nb_commands);
	prg_data->commands[0] = test_command1(prg_data);
	prg_data->commands[1] = test_command2(prg_data);
	prg_data->commands[2] = test_command3(prg_data);
	return (execute(prg_data));
}
