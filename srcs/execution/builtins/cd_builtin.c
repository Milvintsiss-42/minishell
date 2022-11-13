/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/13 21:43:45 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	updates_env_pwd(t_prg_data *prg_data)
{
	char	*pwd;
	char	*old_pwd;
	int		rstatus;

	if (get_env_element_address_by_name(prg_data, "PWD") != 0)
	{
		old_pwd = get_env_element_value_by_name(prg_data, "PWD");
		if (!old_pwd)
			return (ft_perror_errno(*prg_data));
		rstatus = add_or_modify_env_element_if_exists(prg_data,
				"OLDPWD", old_pwd);
		free(old_pwd);
		if (rstatus != 0)
			return (rstatus);
	}
	pwd = get_pwd();
	if (!pwd)
		return (ft_perror_errno(*prg_data));
	rstatus = add_or_modify_env_element_if_exists(prg_data, "PWD", pwd);
	free(pwd);
	return (rstatus);
}

int	exec_cd_builtin(t_prg_data *prg_data, t_command *command)
{
	if (chdir(command->args[1]) == -1)
		return (ft_perror_errno(*prg_data) * 0);
	return (updates_env_pwd(prg_data));
}
