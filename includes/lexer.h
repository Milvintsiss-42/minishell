/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:54:23 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/25 21:17:39 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "common.h"
# include "tokenizer.h"
# include "parsing.h"

t_lst_tokens				*lexer(t_lst_tokens *tokens, t_prg_data *prog_data);

#endif