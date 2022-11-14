/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:56:24 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/14 03:43:02 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	remove_env_element_from_arg(t_prg_data *prg_data, char *arg)
{
	char	*name;

	name = arg;
	if (!is_name_identifier_valid(name))
		return (error_invalid_identifier(prg_data, "unset"));
	return (remove_env_element(prg_data, name));
}

int	exec_unset_builtin(t_prg_data *prg_data, t_command *command)
{
	char	**args;
	int		rstatus;
	int		i;

	args = command->args + 1;
	i = 0;
	while (args[i])
	{
		rstatus = remove_env_element_from_arg(prg_data, args[i]);
		if (rstatus > 0)
			return (rstatus);
		i++;
	}
	return (0);
}
