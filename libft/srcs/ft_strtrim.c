/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 04:05:48 by ple-stra          #+#    #+#             */
/*   Updated: 2021/12/03 00:05:33 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcontain(char const *s1, char const c)
{
	while (*s1)
		if (*s1++ == c)
			return (1);
	return (0);
}

static char	*ft_empty_string(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*start;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strcontain(set, *s1))
		s1++;
	start = (char *)s1;
	if (!*start)
		return (ft_empty_string());
	while (*s1)
		s1++;
	while (--s1 != start && ft_strcontain(set, *s1))
		;
	len = ++s1 - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (start != s1)
		*str++ = *start++;
	*str = 0;
	return (str - len);
}

// int	main(void)
// {
// 	printf("%s", ft_strtrim("   xxx   xxx", " x"));
// }
