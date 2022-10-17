/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:36:38 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/13 17:50:18 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// returns the number of commands in the line
// handles | || &&
// reads the line and counts the | || &&
// doesn't count the | || && if they are in quotes
static int	get_nb_commands(char *line)
{
	int		i;
	int		amount;
	t_bool	in_squote;
	t_bool	in_dquote;
	int		len;

	i = 0;
	amount = 1;
	len = ft_strlen(line);
	in_squote = FALSE;
	in_dquote = FALSE;
	while (line[i] && i < len && ++i)
	{
		if (!in_squote && line[i] == '\"')
			in_dquote = !in_dquote;
		if (!in_dquote && line[i] == '\'')
			in_squote = !in_squote;
		if (!in_squote && !in_dquote && line[i] == '|' && ++amount)
			if (i + 1 < len && line[i + 1] == '|')
				i++;
		if (!in_squote && !in_dquote && (line[i] == '&' && i + 1 < len
				&& line[i + 1] == '&') && ++amount)
			i++;
	}
	return (amount);
}

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
	if (!parsing_validation(prg_data, line))
		return (NULL);
	if (get_nb_commands(line) == cmd_no)
		return (NULL);
	return (get_commands(prg_data, line, cmd_no));
}
