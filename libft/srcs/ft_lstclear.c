/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:56:06 by ple-stra          #+#    #+#             */
/*   Updated: 2021/12/02 23:00:33 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iter;
	t_list	*tmp;

	iter = *lst;
	*lst = NULL;
	while (iter)
	{
		tmp = iter;
		iter = iter->next;
		ft_lstdelone(tmp, del);
	}
}	
