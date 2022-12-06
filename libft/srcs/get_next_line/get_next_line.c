/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:17:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/06 17:00:11 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(t_gnlstring *l_line, size_t line_len, char **sbuf);
static int	loop(t_gnlstring **l_line, size_t *line_len, char **sbuf,
				t_gnlbuf *buf);

// TODO: removes this in the future
static void	init_buf(t_gnlbuf *buf, char *sbuf, int fd)
{
	buf->len = gnl_strllen(sbuf, 0, GNL_BUFFER_SIZE);
	buf->rlen = gnl_strllen(sbuf, '\n', buf->len);
	buf->fd = fd;
}

char	*get_next_line(int fd, int do_free)
{
	t_gnlstring		*l_line;
	static char		*sbuf[10240];
	t_gnlbuf		buf;
	size_t			line_len;

	l_line = NULL;
	line_len = 0;
	if (do_free == 1)
		return (gnl_free_all(l_line, &sbuf[fd]));
	if (!sbuf[fd])
	{
		sbuf[fd] = malloc(sizeof(char) * GNL_BUFFER_SIZE);
		*sbuf[fd] = 0;
		if (!sbuf[fd])
			return (NULL);
	}
	init_buf(&buf, sbuf[fd], fd);
	if (!loop(&l_line, &line_len, &sbuf[fd], &buf))
		return (NULL);
	if (buf.len == -1 || l_line == NULL)
		return (gnl_free_all(l_line, &sbuf[fd]));
	*sbuf[fd] = 0;
	if ((size_t)buf.len > buf.rlen)
		gnl_save(&sbuf[fd], sbuf[fd] + buf.rlen, buf.len - buf.rlen);
	return (get_line(l_line, line_len, &sbuf[fd]));
}

static int	loop(t_gnlstring **l_line, size_t *line_len, char **sbuf,
				t_gnlbuf *buf)
{
	while (1)
	{
		if (buf->rlen || buf->len)
		{
			*line_len += buf->rlen;
			*l_line = gnl_addtolist(*l_line, buf->rlen, sbuf);
			if (!*l_line)
				return (0);
			if (buf->len - buf->rlen > 0
				|| (buf->rlen > 0 && *(*sbuf + buf->rlen - 1) == '\n'))
				break ;
		}
		buf->len = read(buf->fd, *sbuf, GNL_BUFFER_SIZE);
		if ((GNL_BREAK_ON_EOF_MID_LINE && buf->len <= 0)
			|| (buf->len < 0 || (buf->len == 0 && *line_len == 0)))
			break ;
		buf->rlen = gnl_strllen(*sbuf, '\n', buf->len);
	}
	return (1);
}

static char	*get_line(t_gnlstring *l_line, size_t line_len, char **sbuf)
{
	char		*line;
	t_gnlstring	*to_free;
	char		*str;

	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (gnl_free_all(l_line, sbuf));
	line += line_len;
	*line-- = 0;
	while (l_line)
	{
		str = l_line->string + l_line->len;
		while (l_line->len--)
			*line-- = *--str;
		to_free = l_line;
		l_line = l_line->previous;
		free(to_free->string);
		free(to_free);
	}
	return (line + 1);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char const **argv)
// {
// 	int		fd;
// 	char	*line;

// 	(void)argc;
// 	fd = open(argv[1], O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
