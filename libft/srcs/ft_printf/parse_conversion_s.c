/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:52:19 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:42:53 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfparsestring(t_ptfmod mod, t_list **print, char *s)
{
	char	*str;
	int		len;

	if (s == NULL)
		str = STR_NULL;
	else
		str = s;
	len = ft_strlen(str);
	if (ft_checkflag(mod.flags, FLAG_PREC) && (long)mod.prec < len && s == NULL)
		len = 0;
	if (ft_checkflag(mod.flags, FLAG_PREC))
		len = ft_min(len, mod.prec);
	if (!ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_ptfaddpad(print, mod.width - len))
			return (-1);
	if (!(ft_checkflag(mod.flags, FLAG_PREC) && (long)mod.prec < len
			&& s == NULL))
		if (!ft_ptfaddstr(print, str, len))
			return (-1);
	if (ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_ptfaddpad(print, mod.width - len))
			return (-1);
	len = ft_max(len, mod.width);
	return (len);
}
