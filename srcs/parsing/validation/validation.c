/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:32:19 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/13 17:08:38 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

static t_bool	check_quotes(char *line)
{
	int		i;
	int		len;
	t_bool	in_squote;
	t_bool	in_dquote;

	i = 0;
	len = ft_strlen(line);
	in_squote = FALSE;
	in_dquote = FALSE;
	while (line[i] && i < len)
	{
		if (!in_squote && line[i] == '\"')
			in_dquote = !in_dquote;
		if (!in_dquote && line[i] == '\'')
			in_squote = !in_squote;
		i++;
	}
	return (in_squote || in_dquote);
}

static t_bool	check_parenthesis(char *line)
{
	int		i;
	int		len;
	t_bool	in_squote;
	t_bool	in_dquote;
	int		in_parenthesis;

	i = 0;
	len = ft_strlen(line);
	in_squote = FALSE;
	in_dquote = FALSE;
	in_parenthesis = 0;
	while (line[i] && i < len)
	{
		if (!in_squote && line[i] == '\"')
			in_dquote = !in_dquote;
		if (!in_dquote && line[i] == '\'')
			in_squote = !in_squote;
		if (!in_squote && !in_dquote && line[i] == '(')
			in_parenthesis++;
		if (!in_squote && !in_dquote && line[i] == ')')
			in_parenthesis--;
		i++;
	}
	return (in_parenthesis != 0);
}

// TODO: add parsing validation such as opening and closing quotes, single &...
// prints the parsing error too and returns false
t_bool	parsing_validation(t_prg_data *prg_data, char *line)
{
	if (check_quotes(line))
		return (!ft_fperror(*prg_data, "syntax error", "unclosed quote"));
	if (check_parenthesis(line))
		return (!ft_fperror(*prg_data, "syntax error", "unclosed parenthesis")); // TODO: is the error message correct?
	// TODO: check for && || | ect ...
	return (TRUE);
}
