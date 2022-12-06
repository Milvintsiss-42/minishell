/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:46:23 by ple-stra          #+#    #+#             */
/*   Updated: 2021/12/02 21:56:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l_new;

	l_new = malloc(sizeof(t_list));
	if (!l_new)
		return (NULL);
	l_new->content = content;
	l_new->next = NULL;
	return (l_new);
}	
