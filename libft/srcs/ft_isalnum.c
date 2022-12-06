/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:11:15 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/28 02:06:53 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) | ft_isdigit(c));
}	

// int	main(void)
// {
// 	int	i;

// 	i = -100;
// 	while (++i < 100)
// 	{
// 		if (ft_isalnum(i) != isalnum(i))
// 		{
// 			printf("nb: %d\n", i);
// 			printf("ft_isalnum: %d\n", ft_isalnum(i));
// 			printf("isalnum: %d\n\n", isalnum(i));
// 		}
// 	}
// }
