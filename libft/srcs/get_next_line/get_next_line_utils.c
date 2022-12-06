/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:21:07 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/06 16:48:40 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strllen(char const *str, char c, size_t l)
{
	char	*str2;

	if (!str)
		return (0);
	str2 = (char *)str;
	l++;
	while (--l && *str != c)
		str++;
	if (l && *str == c && c != 0)
		return (str - str2 + 1);
	return (str - str2);
}

void	*gnl_free_all(t_gnlstring *l_line, char **sbuf)
{
	t_gnlstring	*to_free;

	if (*sbuf)
		free(*sbuf);
	*sbuf = 0;
	while (l_line)
	{
		to_free = l_line;
		l_line = l_line->previous;
		if (to_free->string)
			free(to_free->string);
		free(to_free);
	}
	return (NULL);
}

t_gnlstring	*gnl_addtolist(t_gnlstring *l_line, size_t real_len, char **sbuf)
{
	t_gnlstring	*new;
	char		*buf;
	char		*str;

	if (real_len == 0)
		return (l_line);
	new = malloc(sizeof(t_gnlstring));
	if (!new)
		return (gnl_free_all(l_line, sbuf));
	new->len = real_len;
	new->previous = l_line;
	new->string = malloc(sizeof(char) * (real_len));
	if (!new->string)
		return (gnl_free_all(new, sbuf));
	buf = *sbuf;
	str = new->string;
	while (real_len--)
		*str++ = *buf++;
	return (new);
}

void	gnl_save(char **sbuf, char *to_save, size_t len)
{
	char	*str;

	str = *sbuf;
	while (len--)
		*str++ = *to_save++;
	if (str - *sbuf <= GNL_BUFFER_SIZE)
		*str = 0;
}
