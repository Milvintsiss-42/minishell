/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:03:50 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/28 17:45:06 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	is_invalid(t_lst_tokens *token)
{
	if ((!token->next && is_separator(token->token) != e_CLOSE_PRTH))
		return (TRUE);
	if ((is_separator(token->token) == e_RD_FILE
			|| is_separator(token->token) == e_RD_STDIN
			|| is_separator(token->token) == e_RD_FILE_APN
			|| is_separator(token->token) == e_RD_STDIN_HEREDOC)
		&& token->next && is_separator(token->next->token) == e_OPEN_PRTH)
		return (TRUE);
	if ((token->next && is_separator(token->next->token)
			&& is_separator(token->next->token) != e_OPEN_PRTH)
		&& is_separator(token->token) != e_CLOSE_PRTH)
		return (TRUE);
	if (is_separator(token->token) == e_OPEN_PRTH
		&& is_separator(token->next->token) == e_CLOSE_PRTH)
		return (TRUE);
	if (is_separator(token->token) == e_OPEN_PRTH && token->prev
		&& !is_separator(token->prev->token))
		return (TRUE);
	if (is_separator(token->token) == e_CLOSE_PRTH && token->next
		&& is_separator(token->next->token) == e_OPEN_PRTH)
		return (TRUE);
	return (FALSE);
}

t_bool	check_syntax(t_lst_tokens *tokens)
{
	while (tokens)
	{
		if (is_separator(tokens->token))
		{
			if (is_invalid(tokens))
			{
				ft_printf_fd(2, "syntax error near '%s'\n",
					tokens->token);
				return (FALSE);
			}
		}
		tokens = tokens->next;
	}
	return (TRUE);
}
