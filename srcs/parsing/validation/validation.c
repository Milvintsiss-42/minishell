/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:39:29 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/07 16:39:14 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_all_quotes_closed(char *line)
{
	char	quote;
	size_t	opened_quotes;

	opened_quotes = 0;
	while (line && *line)
	{
		if (quote == '\0' && (*line == '\'' || *line == '\"'))
		{
			quote = *line;
			opened_quotes++;
		}
		else if (quote == *line)
		{
			quote = '\0';
			opened_quotes--;
		}
		line++;
	}
	return (opened_quotes);
}

int	is_all_parenthesis_closed(char *line)
{
	size_t	opened_parenthesis;

	opened_parenthesis = 0;
	while (line && *line)
	{
		if (*line == '(')
			opened_parenthesis++;
		else if (*line == ')')
			opened_parenthesis--;
		line++;
	}
	return (opened_parenthesis);
}

int	validate_input(char *line)
{
	if (is_all_quotes_closed(line) != 0)
	{
		printf("%s\n", ERR_LONELY_SYMBOLS);
		return (-1);
	}
	if (is_all_parenthesis_closed(line) != 0)
	{
		printf("%s\n", ERR_LONELY_SYMBOLS);
		return (-1);
	}
	// TODO: check for << and >> and other symbols syntax error ()
	return (0);
}
