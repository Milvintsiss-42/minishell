/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:25:00 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/03 20:39:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Write [str] to standard output and return the len of [str]
size_t	ft_putstr(const char *str)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (0);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
