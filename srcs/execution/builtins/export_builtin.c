/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:43:05 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/29 19:39:36 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	add_env_element_from_arg(t_prg_data *prg_data, char *arg)
{
	char	*name;
	char	*value;

	value = ft_strchr(arg, '=');
	if (!value)
	{
		if (!is_name_identifier_valid(arg))
			return (error_invalid_identifier(prg_data, "export"));
		return (-1);
	}
	*value = 0;
	value++;
	name = arg;
	if (ft_strncmp(name, "PWD", 4) == 0 || ft_strncmp(name, "OLDPWD", 7) == 0)
		ft_fperror(*prg_data, "export", ERR_LOCKED_ENV_VAR);
	if (!is_name_identifier_valid(name))
		return (error_invalid_identifier(prg_data, "export"));
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
		if (rstatus > 1)
			return (rstatus);
		i++;
	}
	return (0);
}
