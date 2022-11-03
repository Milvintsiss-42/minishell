/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:53:34 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/02 18:43:52 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "common.h"
# include "tokens.h"
# include "parsing.h"

t_lst_tokens	*tokenizer(char *line);
size_t			skip_quotes(char *line);
void			*free_tokenizer(t_lst_tokens *tokens);
size_t			lst_tokens_size(t_lst_tokens *tokens);
t_lst_tokens	*lst_tokens_last(t_lst_tokens *lst);
t_lst_tokens	*add_new_token(t_lst_tokens *tokens, char *value);

#endif