/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:07:36 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:42:13 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfgetflags(const char **fmt)
{
	int	flags;

	flags = 0x0;
	while (**fmt)
	{
		if (**fmt == '#')
			ft_setflag(&flags, FLAG_ALTER);
		else if (**fmt == ' ')
			ft_setflag(&flags, FLAG_SPACE);
		else if (**fmt == '-')
			ft_setflag(&flags, FLAG_PADR);
		else if (**fmt == '0')
			ft_setflag(&flags, FLAG_ZERO);
		else if (**fmt == '+')
			ft_setflag(&flags, FLAG_PLUS);
		else
			break ;
		(*fmt)++;
	}
	return (flags);
}

unsigned int	ft_ptfgetwidth(const char **fmt)
{
	unsigned int	width;

	width = ft_atoi(*fmt);
	while (**fmt && ft_isdigit(**fmt))
		(*fmt)++;
	return (width);
}

unsigned int	ft_ptfgetprecision(const char **fmt, int *flags)
{
	unsigned int	precision;

	if (**fmt != '.')
		return (0);
	(*fmt)++;
	ft_setflag(flags, FLAG_PREC);
	precision = ft_atoi(*fmt);
	while (**fmt && ft_isdigit(**fmt))
		(*fmt)++;
	return (precision);
}

t_ptfmod	ft_ptfhandle_args_exceptions(t_ptfmod mod)
{
	if (ft_checkflag(mod.flags, FLAG_PADR))
		ft_resetflag(&mod.flags, FLAG_ZERO);
	if (ft_checkflag(mod.flags, FLAG_PLUS))
		ft_resetflag(&mod.flags, FLAG_SPACE);
	if (ft_checkflag(mod.flags, FLAG_PREC))
		ft_resetflag(&mod.flags, FLAG_ZERO);
	if (!ft_checkflag(mod.flags, FLAG_PREC)
		&& ft_checkflag(mod.flags, FLAG_ZERO)
		&& mod.width != 0)
	{
		if (ft_checkflag(mod.flags, FLAG_ALTER))
		{
			if (mod.width > 2)
				mod.width = mod.width - 2;
			else
				mod.width = 0;
		}
		mod.prec = mod.width;
		ft_setflag(&mod.flags, FLAG_PREC);
	}
	return (mod);
}
