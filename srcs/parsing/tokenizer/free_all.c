/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:27:30 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/07 15:28:53 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	*free_tokenizer(t_lst_tokens *tokens)
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
