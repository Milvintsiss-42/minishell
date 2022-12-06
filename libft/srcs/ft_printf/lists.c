/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:25:33 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:40:08 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfaddstr(t_list **lst, const char *str, size_t len)
{
	t_ptfstr	*sstr;
	t_list		*new;

	sstr = malloc(sizeof(t_ptfstr));
	if (!sstr)
		return (0);
	sstr->str = malloc(sizeof(char) * len);
	if (!sstr->str)
		return (ft_free(sstr));
	sstr->str = ft_memcpy(sstr->str, str, len);
	sstr->len = len;
	new = ft_lstnew(sstr);
	if (!new)
		return (ft_ptffreestr(sstr));
	ft_lstadd_back(lst, new);
	return (1);
}

int	ft_ptffreestr(t_ptfstr *sstr)
{
	if (sstr)
		free(sstr->str);
	free(sstr);
	return (0);
}

int	ft_ptfclearlst(t_list *lst)
{
	t_list	*to_free;

	while (lst)
	{
		to_free = lst;
		lst = lst->next;
		ft_ptffreestr(to_free->content);
		free(to_free);
	}
	return (-1);
}
