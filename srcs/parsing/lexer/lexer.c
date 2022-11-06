/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:48:29 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/06 22:25:37 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "tokenizer.h"
#include "parsing.h"
#include "tokens.h"

void	set_separators(t_lst_tokens *tokens)
{
	t_token_separator	separator;

	while (tokens)
	{
		separator = is_separator(tokens->token);
		if (separator)
		{
			tokens->sep = separator;
			tokens->is_separator = TRUE;
		}
		tokens = tokens->next;
	}
}

void	set_is_inparenthesis(t_lst_tokens *tokens)
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

/*
* Attach some Metadata to the tokens from the tokenizer.
*/
t_lst_tokens	*lexer(t_lst_tokens *tokens, t_prg_data *prog_data)
{
	set_separators(tokens);
	set_is_inparenthesis(tokens);
	quotes_handling(tokens);
	(void) prog_data;
	return (tokens);
}
