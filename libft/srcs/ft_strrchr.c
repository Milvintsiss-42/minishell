/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:19:20 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/30 20:07:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occur;

	last_occur = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last_occur = s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	else
		return ((char *)last_occur);
}	
