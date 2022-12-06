/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:59:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/28 21:42:31 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptfinvalidconversion(t_list **print)
{
	if (!ft_ptfaddstr(print, INV_FMT, ft_strlen(INV_FMT)))
		return (-1);
	return (ft_strlen(INV_FMT));
}
