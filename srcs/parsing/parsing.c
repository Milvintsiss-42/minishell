/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:36:38 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/11 17:42:51 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// Takes as input the raw user input from the shell
// Will fill the program data struct with the commands to exec
// Also checks if the line is not empty
t_command	*parsing(t_prg_data *prg_data, char *line, int cmd_no)
{
	(void)prg_data;
	if (!line || !*line)
		return (NULL);
	while (*line == ' ' || *line == '\t') // TODO: check if all whitespaces are ignored in the command input or just space and tab
		line++;
	// TODO: add parsing validation such as opening and closing quotes, single &...
	if (!parsing_validation(prg_data, line))
		return (NULL);
	return (get_commands(prg_data, line, cmd_no));
}
