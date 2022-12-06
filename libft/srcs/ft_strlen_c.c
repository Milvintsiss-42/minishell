/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:36:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/26 14:37:22 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Return the len until [end_c] or [\0].
size_t	ft_strlen_c(const char *s, char end_c)
{
	const char	*s2;

	s2 = s;
	while (*s2 && *s2 != end_c)
		s2++;
	return (s2 - s);
}	
