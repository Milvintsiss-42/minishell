/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:43:36 by oaarsse           #+#    #+#             */
/*   Updated: 2022/09/05 18:13:00 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// parse the line to separate each commands (seps: | || &&)
// returns an array of commands
t_command	*get_commands(char *line)
{
	int		i;
	int		amount;
	char	**cmds;

	i = 0;
	amount = get_nb_commands(line);
	cmds = malloc(sizeof(char *) * 2);
	if (!cmds)
		return (NULL);
	return ;
}

// returns the number of commands in the line
// handles | || &&
int	get_nb_commands(char *line)
{
	int		i;
	int		amount;
	bool	quote;

	i = 0;
	amount = 0;
	quote = false;
	while (line[i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && line[i - 1] != '\\')
			quote = !quote;
		if // TODO: check for separators ( | || &&)
			amount++;
		i++;
	}
	return (0);
}
