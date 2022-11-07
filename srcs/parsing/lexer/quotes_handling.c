/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:25:09 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/07 15:13:55 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	*quotes_removal(t_lst_tokens *token, size_t start, size_t end)
{
	char	*new_token;
	size_t	i;
	size_t	j;

	if (!token->token || *token->token == '\0')
		return (token->token);
	new_token = malloc(sizeof(char) * (ft_strlen(token->token) - 1));
	if (!new_token)
		return (NULL);
	i = 0;
	j = 0;
	while (token->token && token->token[i])
	{
		if (!(i == start || i == end))
		{
			new_token[j] = token->token[i];
			j++;
		}
		i++;
	}
	new_token[j] = '\0';
	free(token->token);
	token->token = new_token;
	return (token->token);
}

static int	remove_grouped_quotes(t_lst_tokens *token)
{
	char		quote;
	size_t		start_pos;
	size_t		i;

	quote = '\0';
	i = 0;
	while (token && token->token[i] && i < ft_strlen(token->token))
	{
		if (quote == '\0' && (token->token[i] == '\''
				|| token->token[i] == '\"'))
		{
			quote = token->token[i];
			start_pos = i;
		}
		else if (quote != '\0' && token->token[i] == quote)
		{
			quote = '\0';
			if (!quotes_removal(token, start_pos, i))
				return (-1);
			i += -2;
		}
		i++;
	}
	return (1);
}

void	*quotes_handling(t_lst_tokens *tokens)
{
	t_lst_tokens	*start;

	start = tokens;
	while (tokens)
	{
		if (remove_grouped_quotes(tokens) == -1)
			return (NULL);
		tokens = tokens->next;
	}
	return (start);
}
