/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:01:46 by ple-stra          #+#    #+#             */
/*   Updated: 2021/12/02 23:30:22 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}	

// #include "stdio.h"
// int	main(void)
// {
// 	t_list	*l;

// 	l = NULL;
// 	ft_lstlast(l);
// 	l = ft_lstnew((void *)1);
// 	printf("%p\n", ft_lstlast(l));
// }
