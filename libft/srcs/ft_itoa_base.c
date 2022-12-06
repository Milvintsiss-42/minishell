/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:51:40 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/16 18:40:40 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Build a string representation of int [n] in the requested [base].
/// [base] is not checked, [base] must be in a valid format.
char	*ft_itoa_base(int n, const char *base)
{
	size_t	len;
	int		tmp_n;
	char	*str;
	int		b_len;

	b_len = (int)ft_strlen(base);
	len = n <= 0;
	tmp_n = n;
	while (tmp_n && ++len)
		tmp_n /= b_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str += len;
	*str = 0;
	tmp_n = n;
	while (tmp_n)
	{
		*--str = base[tmp_n % b_len * (-1 + 2 * (n >= 0))];
		tmp_n /= b_len;
	}
	if (n <= 0)
		*--str = '-' + 3 * (n == 0);
	return (str);
}

/// Build a string representation of unsigned int [n] in the requested [base].
/// [base] is not checked, [base] must be in a valid format.
char	*ft_itoa_base_u(unsigned int n, const char *base)
{
	size_t			len;
	unsigned int	tmp_n;
	char			*str;
	unsigned int	b_len;

	b_len = (unsigned int)ft_strlen(base);
	len = n == 0;
	tmp_n = n;
	while (tmp_n && ++len)
		tmp_n /= b_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str += len;
	*str = 0;
	tmp_n = n;
	while (tmp_n)
	{
		*--str = base[tmp_n % b_len];
		tmp_n /= b_len;
	}
	if (n == 0)
		*--str = '0';
	return (str);
}

/// Build a string representation of unsigned long [n] in the requested [base].
/// [base] is not checked, [base] must be in a valid format.
char	*ft_itoa_base_ul(unsigned long n, const char *base)
{
	size_t			len;
	unsigned long	tmp_n;
	char			*str;
	unsigned long	b_len;

	b_len = (unsigned long)ft_strlen(base);
	len = n == 0;
	tmp_n = n;
	while (tmp_n && ++len)
		tmp_n /= b_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str += len;
	*str = 0;
	tmp_n = n;
	while (tmp_n)
	{
		*--str = base[tmp_n % b_len];
		tmp_n /= b_len;
	}
	if (n == 0)
		*--str = '0';
	return (str);
}
