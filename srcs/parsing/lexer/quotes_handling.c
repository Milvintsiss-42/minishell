/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:25:09 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/06 23:05:53 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	*quotes_removal(t_lst_tokens *token, size_t start, size_t end)
{
	char	*new_token;
	size_t	i;
	size_t	j;

	new_token = malloc(sizeof(char) * (ft_strlen(token->token) - 1));
	if (!new_token)
		return (NULL);
	i = 0;
	j = 0;
	while (token->token[i])
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

void	*quotes_handling(t_lst_tokens *tokens)
{
	char		quote;
	size_t		start_pos;
	size_t		end_pos;
	size_t		i;

	quote = '\0';
	while (tokens)
	{
		i = 0;
		while (tokens->token[i])
		{
			i++;
		}
		tokens = tokens->next;
	}
	return (tokens);
}
