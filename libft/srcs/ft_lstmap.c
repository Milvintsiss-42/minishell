/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:08:55 by ple-stra          #+#    #+#             */
/*   Updated: 2021/12/02 23:45:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*l_new;

	if (!lst)
		return (NULL);
	l_new = ft_lstnew((*f)(lst->content));
	if (!l_new)
		return (NULL);
	start = l_new;
	while (lst->next)
	{
		lst = lst->next;
		l_new->next = ft_lstnew((*f)(lst->content));
		if (!l_new)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		l_new = l_new->next;
	}
	return (start);
}	
