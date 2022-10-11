/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:02:12 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/11 16:41:00 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// returns the number of commands in the line
// handles | || &&
// reads the line and counts the | || &&
// doesn't count the | || && if they are in quotes
// static int	get_nb_commands(char *line)
// {
// 	int		i;
// 	int		amount;
// 	t_bool	in_squote;
// 	t_bool	in_dquote;
// 	int		len;

// 	i = 0;
// 	amount = 1;
// 	len = ft_strlen(line);
// 	in_squote = FALSE;
// 	in_dquote = FALSE;
// 	while (line[i] && i < len)
// 	{
// 		if (!in_squote && line[i] == '\"' && i - 1 >= 0 && line[i - 1] != '\\')
// 			in_dquote = !in_dquote;
// 		if (!in_dquote && line[i] == '\'' && i - 1 >= 0 && line[i - 1] != '\\')
// 			in_squote = !in_squote;
// 		if (!in_squote && !in_dquote && line[i] == '|' && ++amount)
// 			if (i + 1 < len && line[i + 1] == '|')
// 				i++;
// 		if (!in_squote && !in_dquote && (line[i] == '&' && i + 1 < len
// 				&& line[i + 1] == '&') && ++amount)
// 			++i;
// 		i++;
// 	}
// 	return (amount);
// }

// returns an array of commands
t_command	*get_commands(t_prg_data *prg_data, char *line, int cmd_no)
{
	t_command	*cmds;

	(void)prg_data;
	(void)line;
	(void)cmd_no;
	(void)cmds;
	return (NULL);
}
