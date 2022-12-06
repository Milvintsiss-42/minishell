/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 05:24:52 by ple-stra          #+#    #+#             */
/*   Updated: 2022/04/16 05:58:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_of_strings(char const *s, char c)
{
	size_t	nb_strings;

	nb_strings = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			nb_strings++;
		while (*s != c && *s)
			s++;
	}
	return (nb_strings);
}

static char	**ft_freesplit_on_error(char **start, char **end)
{
	char	**to_free;

	to_free = start;
	while (start != end)
		free(*start++);
	free(to_free);
	return (NULL);
}

static char	**return_and_null_terminate(char **start, char **end)
{
	*end = NULL;
	return (start);
}

void	ft_freesplit(char **split)
{
	char	**to_free;

	to_free = split;
	while (*split)
		free(*split++);
	free(to_free);
}

char	**ft_split(char const *s, char c)
{
	char		**strings;
	char		**strings_tmp;
	char const	*s_tmp;

	if (!s)
		return (NULL);
	strings = malloc(sizeof(char *) * (get_number_of_strings(s, c) + 1));
	if (!strings)
		return (NULL);
	strings_tmp = strings;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		s_tmp = s;
		while (*s != c && *s)
			s++;
		*strings_tmp = malloc(sizeof(char) * (s - s_tmp + 1));
		if (!*strings_tmp)
			return (ft_freesplit_on_error(strings, strings_tmp));
		ft_strlcpy(*strings_tmp++, s_tmp, s - s_tmp + 1);
	}
	return (return_and_null_terminate(strings, strings_tmp));
}

// int	main(void)
// {
// 	char	**strings;
// 	char	**strings2;

// 	strings = ft_split("Hello world", 'l');
// 	strings2 = strings;
// 	while (*strings)
// 	{
// 		printf("%s\n", *strings);
// 		free(*strings++);
// 	}
// 	free(strings2);
// }
