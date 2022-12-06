/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:51:27 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/26 05:22:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length_dest;
	size_t	length_src;

	length_dest = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (length_dest >= size)
		return (length_src + size);
	i = 0;
	while (i < size - length_dest && src[i])
	{
		dst[i + length_dest] = src[i];
		i++;
	}
	if (i + length_dest < size)
		dst[i + length_dest] = '\0';
	else
		dst[i + length_dest - 1] = '\0';
	return (length_dest + length_src);
}	
