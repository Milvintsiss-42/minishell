/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:15:54 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/03 18:32:40 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Sort [lst] with [cmp] method.
/// [cmp] take the [content] of element [a] and compare it to [b].
/// If [cmp] return a negative value, [b] is placed before [a].
/// If [cmp] return 0 or a positive value the order stay unchanged, so [a] is
/// placed before [b].
/// 
/// Beware that, for simplicity of use, this function only swap the [content]
/// pointers, all [next] pointers stay unchanged.
void	ft_lstsort(t_list *lst, int (*cmp)(void *a, void *b))
{
	t_list	*l_tmp;
	void	*tmp;

	if (!lst)
		return ;
	while (lst->next)
	{
		l_tmp = lst->next;
		while (l_tmp)
		{
			if ((*cmp)(lst->content, l_tmp->content) < 0)
			{
				tmp = lst->content;
				lst->content = l_tmp->content;
				l_tmp->content = tmp;
			}
			l_tmp = l_tmp->next;
		}
		lst = lst->next;
	}
}
