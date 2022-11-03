/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:34:13 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/03 16:39:58 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static char	*add_token(t_lst_tokens *tokens, char *line_start,
		size_t len_to_copy)
{
	if (len_to_copy == 0)
		return (line_start);
	if (len_to_copy == 1 && *line_start == ' ')
		return (line_start + 1);
	if (!add_new_token(tokens, ft_strndup(line_start, len_to_copy)))
		return (NULL);
	return (line_start + len_to_copy);
}

static void	*add_rest_of_line(t_lst_tokens *tokens, char *str, char *last_cpy)
{
	if (last_cpy != str)
	{
		last_cpy = add_token(tokens, last_cpy, str - last_cpy);
		if (!last_cpy)
			return (free_tokenizer(tokens));
	}
	return (tokens);
}

static char	*add_token_and_separator(t_lst_tokens *tokens, char *str,
		char **last_cpy)
{
	*last_cpy = add_token(tokens, *last_cpy, str - *last_cpy);
	if (!last_cpy)
		return (NULL);
	*last_cpy = add_token(tokens, *last_cpy, 1 + (is_separator(str) > 7));
	if (!last_cpy)
		return (NULL);
	return (*last_cpy);
}

/*
* Transforms a stream of characters into tokens ("words").
* Pupose: separate each tokens of the command.
* Returns a list of tokens (char *).
*/
t_lst_tokens	*tokenizer(char *str)
{
	t_lst_tokens		*tokens;
	char				*last_cpy;

	tokens = malloc(sizeof(t_lst_tokens));
	if (!tokens)
		return (NULL);
	memset(tokens, 0, sizeof(t_lst_tokens));
	last_cpy = str;
	while (*str)
	{
		if (is_separator(str) > 0)
		{
			if (!add_token_and_separator(tokens, str, &last_cpy))
				return (free_tokenizer(tokens));
			if (is_separator(str) > 7)
				str++;
		}
		if (*str == SQUOTE || *str == DQUOTE)
			str += skip_quotes(str);
		else
			str++;
	}
	if (!add_rest_of_line(tokens, str, last_cpy))
		return (NULL);
	return (tokens);
}
