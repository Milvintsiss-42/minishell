/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:51:10 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:43:12 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfparseptr(t_ptfmod mod, t_list **print, void *ptr)
{
	char	*str;
	char	*ul;
	int		len;

	if (ptr == NULL)
	{
		str = ft_strdup(PTR_NULL);
		if (!str)
			return (-1);
	}
	else
	{
		ul = ft_itoa_base_ul((unsigned long)ptr, HEX_BASE);
		if (!ul)
			return (-1);
		str = ft_strjoin("0x", ul);
		free(ul);
		if (!str)
			return (-1);
	}
	len = (int)ft_strlen(str);
	return (ft_ptfaddstr_and_padding(mod, print, str, len));
}
