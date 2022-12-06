/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 04:39:19 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/27 23:54:53 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*ptr;

	if (nmenb == 0 || size == 0)
		return (malloc(1));
	if (nmenb * size < nmenb || nmenb * size < size)
		return (NULL);
	ptr = malloc(nmenb * size);
	if (ptr)
		ft_bzero(ptr, nmenb * size);
	return (ptr);
}	
