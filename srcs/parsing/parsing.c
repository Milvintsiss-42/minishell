/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:36:38 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/11 13:36:06 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// Takes as input the raw user input from the shell
// Will fill the program data struct with the commands to exec
// Also checks if the line is not empty
t_command	*parsing(t_prg_data *prg_data, char *line)
{
	(void)prg_data;
	if (!line)
		return (NULL);
	while (*line == ' ' || *line == '\t') // TODO: check if all whitespaces are ignored in the command input or just space and tab
		line++;
	// TODO: add parsing validation such as opening and closing quotes, single &...
	if (!parsing_validation)
		return (NULL);
	return (get_commands(line));
}
