/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 06:44:32 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/18 00:07:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Create a string representation of the int [n]
char	*ft_itoa(int n)
{
	size_t	len;
	int		tmp_n;
	char	*str;

	len = n <= 0;
	tmp_n = n;
	while (tmp_n && ++len)
		tmp_n /= 10;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str += len;
	*str = 0;
	tmp_n = n;
	while (tmp_n)
	{
		*--str = tmp_n % 10 * (-1 + 2 * (n >= 0)) + '0';
		tmp_n /= 10;
	}
	if (n <= 0)
		*--str = '-' + 3 * (n == 0);
	return (str);
}

/// Create a string representation of the unsigned int [n]
char	*ft_itoa_u(unsigned int n)
{
	size_t			len;
	unsigned int	tmp_n;
	char			*str;

	len = n == 0;
	tmp_n = n;
	while (tmp_n && ++len)
		tmp_n /= 10;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str += len;
	*str = 0;
	tmp_n = n;
	while (tmp_n)
	{
		*--str = tmp_n % 10 + '0';
		tmp_n /= 10;
	}
	if (n == 0)
		*--str = '0';
	return (str);
}

/// stupid
/// ints[0] == len
/// ints[1] == tmp_n
/// 
/// ACTUAL SIZE = 19 lines (as counted by norminette)
/// THIS IS NOT THE BEST, WE CAN DO MORE!!! MAHAHAHAHAH
char	*ft_itoa_stupid(int n)
{
	long int	ints[2];
	char		*str;

	ints[0] = n <= 0;
	ints[1] = n;
	while (ints[1] && ++(ints[0]))
		ints[1] /= 10;
	str = malloc(sizeof(char) * (ints[0] + 1)) + ints[0];
	if (!(str - ints[0]))
		return (NULL);
	*str = 0;
	*(str - ints[0]) = '-' + 3 * (n == 0);
	ints[1] = n;
	while (ints[1])
	{
		*--str = ints[1] % 10 * (-1 + 2 * (ints[1] > 0)) + '0';
		ints[1] /= 10;
	}
	return (str - (n <= 0));
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa_stupid(0));
// 	printf("%s\n", ft_itoa_stupid(255));
// 	printf("%s\n", ft_itoa_stupid(-255));
// 	printf("%s\n", ft_itoa_stupid(10));
// 	printf("%s\n", ft_itoa_stupid(-10));
// }
