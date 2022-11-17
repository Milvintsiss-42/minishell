/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export-unset_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:05:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/14 03:10:11 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_name_identifier_valid(char *name)
{
	if (!*name)
		return (0);
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (0);
		name++;
	}
	return (1);
}

int	error_invalid_identifier(t_prg_data *prg_data, char *cmd_name)
{
	ft_fperror(*prg_data, cmd_name, "Invalid identifier");
	return (-1);
}
