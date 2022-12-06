/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:52:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:45:48 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptfparse2(int *total_len, t_list **print, const char *fmt,
				va_list ap);

static int	ft_ptfparseconversion(t_ptfmod mod, t_list **print, const char type,
				va_list ap);

int	ft_ptfparse(t_list **print, const char *format, va_list ap)
{
	const char	*fmt;
	int			total_len;
	int			len_read;

	total_len = 0;
	while (*format)
	{
		fmt = format;
		while (*format && *format != '%')
			format++;
		if (!ft_ptfaddstr(print, fmt, format - fmt))
			return (-1);
		total_len += format - fmt;
		if (*format == '%')
		{
			len_read = ft_ptfparse2(&total_len, print, ++format, ap);
			if (len_read == -1)
				return (-1);
			format += len_read;
		}
	}
	return (total_len);
}

static int	ft_ptfparse2(int *total_len, t_list **print, const char *fmt,
	va_list ap)
{
	t_ptfmod		mod;
	int				r;
	const char		*start;

	start = fmt;
	mod.flags = ft_ptfgetflags(&fmt);
	mod.width = ft_ptfgetwidth(&fmt);
	mod.prec = ft_ptfgetprecision(&fmt, &mod.flags);
	mod = ft_ptfhandle_args_exceptions(mod);
	if (ft_isconversion(*fmt))
		r = ft_ptfparseconversion(mod, print, *fmt, ap);
	else
		r = ft_ptfinvalidconversion(print);
	if (r == -1)
		return (-1);
	*total_len += r;
	fmt++;
	return (fmt - start);
}

static int	ft_ptfparseconversion(t_ptfmod mod, t_list **print, const char type,
	va_list ap)
{
	if (type == '%')
		return (ft_ptfparsechar(mod, print, '%', '%'));
	if (type == 'c')
		return (ft_ptfparsechar(mod, print, (char)va_arg(ap, int), 'c'));
	if (type == 's')
		return (ft_ptfparsestring(mod, print, va_arg(ap, char *)));
	if (type == 'p')
		return (ft_ptfparseptr(mod, print, va_arg(ap, void *)));
	if (type == 'd' || type == 'i')
		return (ft_ptfparseint(mod, print, va_arg(ap, int)));
	if (type == 'u')
		return (ft_ptfparseunsign(mod, print, va_arg(ap, unsigned int),
				DEC_BASE));
	if (type == 'x')
		return (ft_ptfparseunsign(mod, print, va_arg(ap, unsigned int),
				HEX_BASE));
	if (type == 'X')
		return (ft_ptfparseunsign(mod, print, va_arg(ap, unsigned int),
				HEX_BASE_CAPS));
	return (-1);
}
