/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_nu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:22:17 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/08 18:25:42 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	command_nu(t_lst_tokens *tokens)
{
	size_t	nb;

	nb = 1;
	while (tokens)
	{
		if (is_or_and_pipe(tokens->token) != e_NONE)
			nb++;
		tokens = tokens->next;
	}
	return (nb);
}
