/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:05:34 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/17 19:14:36 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add [new] between [alst] and [alst->next], add [new] as first element if 
// [alst] is null.
void	ft_lstadd_next(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else
	{
		new->next = (*alst)->next;
		(*alst)->next = new;
	}
}
