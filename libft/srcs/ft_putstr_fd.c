/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:51:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/03 20:39:32 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Write [str] to [fd] and return the len of [str]
size_t	ft_putstr_fd(const char *str, int fd)
{
	size_t	len;

	if (!str)
	{
		write(fd, "(null)", 6);
		return (0);
	}
	len = ft_strlen(str);
	write(fd, str, len);
	return (len);
}	
