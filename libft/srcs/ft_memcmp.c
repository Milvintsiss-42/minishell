/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:58:40 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/30 20:01:25 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cp;
	const unsigned char	*s2_cp;

	if (n == 0)
		return (0);
	s1_cp = s1;
	s2_cp = s2;
	while (*s1_cp == *s2_cp && --n)
	{
		s1_cp++;
		s2_cp++;
	}
	return (*s1_cp - *s2_cp);
}	
