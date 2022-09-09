/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:58:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/09 16:53:17 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_command	default_command(void)
{
	t_command	command;

	command.cmd = 0;
	command.args = 0;
	command.env = 0;
	command.e_sep = NONE;
	command.read_from_here_doc = FALSE;
	command.here_doc_limiter = 0;
	command.infile = 0;
	command.outfile = 0;
	command.is_append_mode = FALSE;
	command.pipe_in[0] = -1;
	command.pipe_in[1] = -1;
	command.pipe_out[0] = -1;
	command.pipe_out[1] = -1;
	command.is_last = FALSE;
	return (command);
}
