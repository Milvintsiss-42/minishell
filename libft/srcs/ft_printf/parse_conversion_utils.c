/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:34:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:44:38 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfaddpad(t_list **print, int nb)
{
	long int	len;
	char		*str;

	if (nb <= 0)
		return (1);
	len = nb;
	str = malloc(sizeof(char) * nb);
	if (!str)
		return (0);
	while (nb--)
		str[nb] = ' ';
	if (!ft_ptfaddstr(print, str, len))
		return (ft_free(str) - 1);
	free(str);
	return (1);
}

int	ft_ptfaddstr_and_padding(t_ptfmod mod, t_list **print, char *str, int len)
{
	int	r;

	if (!ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_ptfaddpad(print, mod.width - len))
			return (-1);
	r = ft_ptfaddstr(print, str, len);
	free(str);
	if (!r)
		return (-1);
	if (ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_ptfaddpad(print, mod.width - len))
			return (-1);
	return (ft_max(len, mod.width));
}

static char	*ft_createpadzero(unsigned int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	while (len--)
		str[len] = '0';
	return (str);
}

char	*ft_ptfprec(char *str, t_ptfmod mod)
{
	unsigned int	len;
	char			*pad;
	char			*tmp;

	if (!ft_checkflag(mod.flags, FLAG_PREC))
		return (str);
	len = ft_strlen(str);
	if (mod.prec > len)
	{
		pad = ft_createpadzero(mod.prec - len);
		if (!pad)
		{
			free(str);
			return (0);
		}
		tmp = str;
		str = ft_strjoin(pad, str);
		free(pad);
		free(tmp);
	}	
	return (str);
}

int	ft_ptfpreczero_nzero(t_ptfmod mod, t_list **print)
{
	if (!ft_ptfaddpad(print, mod.width))
		return (-1);
	return (mod.width);
}
