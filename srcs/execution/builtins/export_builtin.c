/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:43:05 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/14 02:54:44 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	is_name_valid(char *name)
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

static int	add_env_element_from_arg(t_prg_data *prg_data, char *arg)
{
	char	*name;
	char	*value;

	value = ft_strchr(arg, '=');
	if (!value)
		return (-1);
	*value = 0;
	value++;
	name = arg;
	if (!is_name_valid(name))
		return (ft_fperror(*prg_data,
				"export", "Invalid identifier") * -1);
	return (add_or_modify_env_element_if_exists(prg_data, name, value));
}

int	exec_export_builtin(t_prg_data *prg_data, t_command *command)
{
	char	**args;
	int		rstatus;
	int		i;

	args = command->args + 1;
	i = 0;
	while (args[i])
	{
		rstatus = add_env_element_from_arg(prg_data, args[i]);
		if (rstatus > 0)
			return (rstatus);
		i++;
	}
	return (0);
}
