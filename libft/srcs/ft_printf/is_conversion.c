/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:09:39 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/16 22:30:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isconversion(char c)
{
	return (c == '%' || c == 'c' || c == 's' || ft_isnumericconversion(c));
}

int	ft_ishexconversion(char c)
{
	return (c == 'x' || c == 'X' || c == 'p');
}

int	ft_isnumericconversion(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || ft_ishexconversion(c));
}
