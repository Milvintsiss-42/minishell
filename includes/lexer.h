/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:54:23 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/02 16:58:34 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "common.h"
# include "tokenizer.h"

typedef struct s_lexer
{
	t_lst_tokens			*token;
	size_t					len;

	t_bool					is_separator;
	t_token_separator		sep;
}				t_lexer;

int				lexer(t_lst_tokens *tokens);

#endif