/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:09:44 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/06 17:00:53 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*expand_env_variables_in_line(t_prg_data *prg_data, char *line)
{
	t_arg_cpnt	*arg_cpnts;
	t_arg_cpnt	*arg_cpnts_first;
	char		*startcpnt;

	arg_cpnts = malloc(sizeof(t_arg_cpnt));
	if (!arg_cpnts)
		return (0);
	arg_cpnts_first = arg_cpnts;
	arg_cpnts->next = 0;
	while (*line)
	{
		startcpnt = line;
		while (*line && *line != '$')
			line++;
		if (!handle_expandable(prg_data, &arg_cpnts, &line, &startcpnt))
			return (0);
		if (!*line && !handle_double_quotes_or_0(
				prg_data, &arg_cpnts, &line, &startcpnt))
			return (0);
	}
	arg_cpnts->component = 0;
	return (build_arg(prg_data, arg_cpnts_first));
}

char	*get_next_heredoc_line(t_prg_data *prg_data, t_command *command)
{
	char	*line;
	char	*save;

	line = get_next_line(STDIN_FILENO, 0);
	if (!line || !command->expand_here_doc)
		return (line);
	save = line;
	line = expand_env_variables_in_line(prg_data, line);
	free(save);
	return (line);
}
