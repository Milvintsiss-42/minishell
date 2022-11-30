/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export-unset_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:05:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/28 23:07:54 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_name_identifier_valid(char *name)
{
	if (!*name)
		return (0);
	if (ft_isdigit(*name))
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
	return (1);
}
