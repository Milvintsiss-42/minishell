/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:58:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/17 17:29:52 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_command	default_command(void)
{
	t_command	command;

	command.cmd = 0;
	command.args = 0;
	command.env = 0;
	command.e_sep = sep_NONE;
	command.here_doc_limiter = 0;
	command.infile = 0;
	command.outfile = 0;
	command.is_append_mode = FALSE;
	command.pipe_in[0] = -1;
	command.pipe_in[1] = -1;
	command.pipe_out[0] = -1;
	command.pipe_out[1] = -1;
	command.here_doc_pipe[0] = -1;
	command.here_doc_pipe[1] = -1;
	command.pid = -1;
	command.is_last = FALSE;
	return (command);
}

/// @brief Sets streams enums accordingly to commands parameters and neighbors
/// @param prg_data
void	set_streams_enums(t_prg_data *prg_data)
{
	int			i;
	t_command	*commands;

	i = -1;
	commands = prg_data->commands;
	while (++i < prg_data->nb_commands)
	{
		if (commands[i].here_doc_limiter != 0)
			commands[i].e_stdin = stream_HERE_DOC;
		else if (commands[i].infile != 0)
			commands[i].e_stdin = stream_REDIR;
		else if (i != 0 && commands[i - 1].e_stdout == stream_PIPE)
			commands[i].e_stdin = stream_PIPE;
		else
			commands[i].e_stdin = stream_NONE;
		if (commands[i].outfile != 0)
			commands[i].e_stdout = stream_REDIR;
		else if (i != prg_data->nb_commands - 1
			&& commands[i + 1].here_doc_limiter == 0
			&& commands[i + 1].infile == 0)
			commands[i].e_stdout = stream_PIPE;
		else
			commands[i].e_stdout = stream_NONE;
	}
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
	free(command.here_doc_limiter);
	free(command.infile);
	free(command.outfile);
}
