/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:41:34 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/07 16:41:45 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*free_parsing(t_lst_tokens *tokens)
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
