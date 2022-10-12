/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:58:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/12 18:09:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_command	default_command(void)
{
	t_command	command;

	command.cmd = 0;
	command.args = 0;
	command.env = 0;
	command.e_sep = e_NONE;
	command.read_from_here_doc = FALSE;
	command.here_doc_limiter = 0;
	command.infile = 0;
	command.outfile = 0;
	command.is_append_mode = FALSE;
	command.pipe_in[0] = -1;
	command.pipe_in[1] = -1;
	command.pipe_out[0] = -1;
	command.pipe_out[1] = -1;
	command.pid = -1;
	command.is_last = FALSE;
	return (command);
}

void	reset_commands_data_and_free(t_prg_data *prg_data)
{
	free_commands(prg_data->commands, prg_data->nb_commands);
	prg_data->commands = 0;
	prg_data->nb_commands = 0;
}

void	free_commands(t_command *commands, int nb_commands)
{
	int	i;

	i = -1;
	while (++i < nb_commands)
	{
		free_command_elements(commands[i]);
	}
	free(commands);
}

void	free_command_elements(t_command command)
{
	char	**args;

	free(command.cmd);
	args = command.args;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(command.args);
	// TODO: free(command.env)?
	free(command.here_doc_limiter);
	free(command.infile);
	free(command.outfile);
}
