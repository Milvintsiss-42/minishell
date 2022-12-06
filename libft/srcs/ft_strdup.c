/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 04:58:33 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/17 23:01:09 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	char	*s_iter;

	if (!s)
		return (0);
	s_dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_dup)
		return (0);
	s_iter = s_dup;
	while (*s)
	{
		*(s_iter++) = *(s++);
	}
	*s_iter = 0;
	return (s_dup);
}

/// @brief Malloc a new string of size [n] and cpy [n] characters of [s] in it.
/// Undefined if [n] is bigger than ft_strlen([s]).
/// @param s The string to duplicate.
/// @param n The number of characters to cpy from [s] in the new string.
/// @return Returns a pointer to the new string.
/// If [s] == 0 or malloc fails, returns 0.
char	*ft_strndup(const char *s, size_t n)
{
	char	*s_dup;
	char	*s_iter;

	if (!s)
		return (0);
	s_dup = malloc(sizeof(char) * (n + 1));
	if (!s_dup)
		return (0);
	s_iter = s_dup;
	while (n--)
	{
		*(s_iter++) = *(s++);
	}
	*s_iter = 0;
	return (s_dup);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char 	*result;
// 	char	*to_cpy = "Hello I'm a string";

// 	result = ft_strndup(to_cpy, 5);
// 	printf("%s\n", to_cpy);
// 	printf("%s\n", result);
// }
