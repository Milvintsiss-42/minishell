/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:48:29 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/07 16:00:21 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "tokenizer.h"
#include "parsing.h"
#include "tokens.h"

static void	set_separators(t_lst_tokens *tokens)
{
	t_token_separator	separator;

	while (tokens)
	{
		printf("[LEXER] - set_separator: '%s'\n", tokens->token);
		separator = is_separator(tokens->token);
		if (separator)
		{
			tokens->sep = separator;
			tokens->is_separator = TRUE;
		}
		tokens = tokens->next;
	}
}

static void	set_is_inparenthesis(t_lst_tokens *tokens)
{
	t_bool		in_parenthesis;

	in_parenthesis = FALSE;
	while (tokens)
	{
		if (tokens->sep == e_OPEN_PRTH)
			in_parenthesis = TRUE;
		else if (tokens->sep == e_CLOSE_PRTH)
			in_parenthesis = FALSE;
		tokens->is_in_parenthesis = in_parenthesis;
		tokens = tokens->next;
	}
}

// TODO: should work but need to test it more
static void	*free_all(t_lst_tokens *tokens)
{
	t_lst_tokens	*tmp;

	tmp = tokens;
	while (tokens)
	{
		if (tokens->token)
			free(tokens->token);
		tmp = tokens->next;
		if (tokens)
			free(tokens);
		tokens = tmp;
	}
	return (NULL);
}

/*
* Attach some Metadata to the tokens from the tokenizer.
*/
t_lst_tokens	*lexer(t_lst_tokens *tokens, t_prg_data *prog_data)
{
	(void) prog_data;
	set_separators(tokens);
	set_is_inparenthesis(tokens);
	if (!quotes_handling(tokens))
		return (free_all(tokens));
	return (tokens);
}
