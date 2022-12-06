/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:16:43 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/06 17:00:22 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 42
# endif

# ifndef GNL_BREAK_ON_EOF_MID_LINE
#  define GNL_BREAK_ON_EOF_MID_LINE 1
# endif

typedef struct s_gnlstring
{
	char				*string;
	size_t				len;
	struct s_gnlstring	*previous;
}	t_gnlstring;

typedef struct s_gnlbuf
{
	int		fd;
	size_t	rlen;
	ssize_t	len;
}	t_gnlbuf;

char		*get_next_line(int fd, int do_free);

size_t		gnl_strllen(char const *str, char c, size_t l);
void		*gnl_free_all(t_gnlstring *l_line, char **sbuf);
t_gnlstring	*gnl_addtolist(t_gnlstring *l_line, size_t real_len, char **sbuf);
void		gnl_save(char **sbuf, char *to_save, size_t len);

#endif
