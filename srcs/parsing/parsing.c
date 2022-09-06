/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:36:38 by oaarsse           #+#    #+#             */
/*   Updated: 2022/09/06 13:47:48 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// TODO: check if all whitespaces are ignored in the command input
// Checks for empty line
int	is_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

// Takes as input the raw user input from the shell
// Will fill the program data struct with the commands to exec
// Also checks if the line is not empty
void	parsing(t_prg_data *prg_data, char *line)
{
	t_command	*cmds;

	if (is_empty(line))
		return ;
	cmds = get_commands(line);
	return ;
}
