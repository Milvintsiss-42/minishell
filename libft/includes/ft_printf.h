/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:25:32 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/03 22:34:20 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define INV_FMT "(invalid format)"

# define STR_NULL "(null)"
# ifdef __linux__
#  define PTR_NULL "(nil)"
# else
#  define PTR_NULL "0x0"
# endif

# define FLAG_ALTER		1
# define FLAG_SPACE		2
# define FLAG_PLUS		4
# define FLAG_PADR		8
# define FLAG_ZERO		16
# define FLAG_PREC		32

typedef struct s_ptfstr
{
	char	*str;
	size_t	len;
}	t_ptfstr;

typedef struct s_ptfmod
{
	int				flags;
	unsigned int	width;
	unsigned int	prec;
}	t_ptfmod;

int				ft_printf(const char *format, ...);
int				ft_printf_fd(int fd, const char *format, ...);
int				ft_vasprintf(char **ret, const char *format, ...);

int				ft_ptfparse(t_list **print, const char *format, va_list ap);

int				ft_ptfbuildstr(char **ret, t_list *lst, int len);

int				ft_ptffree_all(t_list *lst);

int				ft_ptfaddstr(t_list **lst, const char *str, size_t len);
int				ft_ptfclearlst(t_list *lst);
int				ft_ptffreestr(t_ptfstr *sstr);

int				ft_isconversion(char c);
int				ft_ishexconversion(char c);
int				ft_isnumericconversion(char c);

int				ft_ptfgetflags(const char **fmt);
unsigned int	ft_ptfgetwidth(const char **fmt);
unsigned int	ft_ptfgetprecision(const char **fmt, int *flags);
t_ptfmod		ft_ptfhandle_args_exceptions(t_ptfmod mod);

int				ft_ptfinvalidconversion(t_list **print);

int				ft_ptfparsechar(t_ptfmod mod, t_list **print, char c,
					char type);
int				ft_ptfparsestring(t_ptfmod mod, t_list **print, char *s);
int				ft_ptfparseptr(t_ptfmod mod, t_list **print, void *ptr);
int				ft_ptfparseint(t_ptfmod mod, t_list **print, int n);
int				ft_ptfparseunsign(t_ptfmod mod, t_list **print, unsigned int n,
					const char *base);

int				ft_ptfaddpad(t_list **print, int nb);
int				ft_ptfaddstr_and_padding(t_ptfmod mod, t_list **print,
					char *str, int len);

char			*ft_ptfprec(char *str, t_ptfmod mod);
int				ft_ptfpreczero_nzero(t_ptfmod mod, t_list **print);

#endif