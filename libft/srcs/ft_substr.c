/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 03:15:34 by ple-stra          #+#    #+#             */
/*   Updated: 2021/12/03 00:06:59 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_tmp;

	if (!s)
		return (NULL);
	len_tmp = ft_strlen(s);
	if (len > len_tmp - start)
		len = len_tmp - start;
	if (start > len_tmp)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		*sub = 0;
		return (sub);
	}
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	s += start;
	len_tmp = len;
	while (len_tmp-- && *s)
		*sub++ = *s++;
	*sub = 0;
	return (sub - len);
}

// int	main(int argc, char **argv)
// {
// 	printf("ft_substr: %s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
// }
