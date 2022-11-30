/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:14:47 by oaarsse           #+#    #+#             */
/*   Updated: 2022/12/01 00:44:19 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

size_t	lst_tokens_size(t_lst_tokens *tokens)
{
	size_t	size;

	size = 0;
	while (tokens)
	{
		size++;
		tokens = tokens->next;
	}
	return (size);
}

t_lst_tokens	*lst_tokens_last(t_lst_tokens *lst)
{
	if (!lst)
		return (NULL);
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

/*
* Adds a new token with the value given to the list of tokens.
*/
t_lst_tokens	*add_new_token(t_lst_tokens *tokens, char *value)
{
	t_lst_tokens	*new_val;
	t_lst_tokens	*last_token;

	if (tokens->token == NULL)
	{
		tokens->token = value;
		tokens->next = NULL;
		tokens->prev = NULL;
		return (tokens);
	}
	last_token = lst_tokens_last(tokens);
	new_val = malloc(sizeof(t_lst_tokens));
	if (!new_val)
		return (NULL);
	ft_memset(new_val, 0, sizeof(t_lst_tokens));
	new_val->token = value;
	new_val->next = NULL;
	new_val->prev = last_token;
	if (last_token)
		last_token->next = new_val;
	return (new_val);
}
