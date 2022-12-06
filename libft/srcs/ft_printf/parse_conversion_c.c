/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:42:53 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfparsechar(t_ptfmod mod, t_list **print, char c, char type)
{
	if (type != '%' && !ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_ptfaddpad(print, mod.width - 1))
			return (-1);
	if (!ft_ptfaddstr(print, &c, 1))
		return (-1);
	if (type != '%' && ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_ptfaddpad(print, mod.width - 1))
			return (-1);
	if (type == '%')
		return (1);
	return (ft_max(mod.width, 1));
}
