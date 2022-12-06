/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:40:18 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/28 02:50:17 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s2;

	s2 = (const unsigned char *)s;
	while (n--)
	{
		if (*s2 == (unsigned char)c)
			return ((void *)s2);
		s2++;
	}
	return (NULL);
}	
