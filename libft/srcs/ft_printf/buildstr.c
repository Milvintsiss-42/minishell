/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:55:29 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:46:02 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfbuildstr(char **ret, t_list *lst, int len)
{
	char		*str;
	t_ptfstr	sstr;

	*ret = malloc(sizeof(char) * (len + 1));
	if (!*ret)
		return (0);
	str = *ret;
	while (lst)
	{
		sstr = *(t_ptfstr *)(lst->content);
		ft_memcpy(str, sstr.str, sstr.len);
		str += sstr.len;
		lst = lst->next;
	}
	*str = 0;
	return (1);
}
