/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:23:33 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:24:27 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf2(const char *format, va_list ap, int fd);
static int	ft_vasprintf2(char **ret, const char *format, va_list ap);

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_printf2(format, ap, 1);
	va_end(ap);
	return (len);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_printf2(format, ap, fd);
	va_end(ap);
	return (len);
}

int	ft_vasprintf(char **ret, const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vasprintf2(ret, format, ap);
	va_end(ap);
	return (len);
}

static int	ft_printf2(const char *format, va_list ap, int fd)
{
	char	*str;
	int		len;

	len = ft_vasprintf2(&str, format, ap);
	write(fd, str, len);
	free(str);
	return (len);
}

static int	ft_vasprintf2(char **ret, const char *format, va_list ap)
{
	t_list	*print;
	int		len;

	(void)ap;
	print = 0;
	len = ft_ptfparse(&print, format, ap);
	if (len == -1)
		return (ft_ptffree_all(print));
	if (!ft_ptfbuildstr(ret, print, len))
		return (ft_ptffree_all(print));
	ft_ptffree_all(print);
	return (len);
}
