/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:58:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/02 17:59:16 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_command	default_command(void)
{
	t_command	command;

	command.args = 0;
	command.e_sep = e_NONE;
	command.is_opening_parenthesis = FALSE;
	command.is_closing_parenthesis = FALSE;
	command.here_doc_limiter = 0;
	command.expand_here_doc = FALSE;
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
