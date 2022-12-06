/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_di.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:50:12 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:44:38 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add_pluschar_and_space(char *str, t_ptfmod mod, int n)
{
	char	*tmp;

	if (!(ft_checkflag(mod.flags, FLAG_PLUS)
			|| ft_checkflag(mod.flags, FLAG_SPACE)
			|| n < 0))
		return (str);
	tmp = str;
	if (n < 0)
		str = ft_strjoin("-", str);
	else if (ft_checkflag(mod.flags, FLAG_PLUS))
		str = ft_strjoin("+", str);
	else
		str = ft_strjoin(" ", str);
	free(tmp);
	return (str);
}

int	ft_ptfparseint(t_ptfmod mod, t_list **print, int n)
{
	char	*str;
	int		len;

	if (n == 0 && ft_checkflag(mod.flags, FLAG_PREC) && mod.prec == 0)
		return (ft_ptfpreczero_nzero(mod, print));
	if (n > 0)
		str = ft_itoa(n);
	else
		str = ft_itoa_u((unsigned int)(-(long int)n));
	if (!str)
		return (-1);
	if (mod.prec > 0 && n < 0 && ft_checkflag(mod.flags, FLAG_ZERO))
		mod.prec -= 1;
	str = ft_ptfprec(str, mod);
	if (!str)
		return (-1);
	str = ft_add_pluschar_and_space(str, mod, n);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	return (ft_ptfaddstr_and_padding(mod, print, str, len));
}
