/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:16:37 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/23 00:18:02 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns biggest number between [a] and [b].
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

// Returns smallest number between [a] and [b].
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
