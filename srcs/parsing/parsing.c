/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:36:38 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/06 18:09:18 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// Checks for empty line
static int	is_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (!ft_isspace(line[i])) // TODO: check if all whitespaces are ignored in the command input
			return (0);
		i++;
	}
	return (1);
}

// Takes as input the raw user input from the shell
// Will fill the program data struct with the commands to exec
// Also checks if the line is not empty
t_command	**parsing(t_prg_data *prg_data, char *line)
{
	if (is_empty(line))
		return (NULL);
	// TODO: check if all whitespaces are ignored in the command input or just space and tab
	while (*line == ' ' || *line == '\t')
		line++;
	// TODO: add parsing validation such as opening and closing quotes no sinle &...
	return (get_commands(line));
}
