/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 13:43:00 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	updates_env_pwd_and_oldpwd(t_prg_data *prg_data)
{
	int		rstatus;
	char	*old_pwd;

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
	return (updates_env_pwd(prg_data, FALSE));
}

int	updates_env_pwd(t_prg_data *prg_data, t_bool from_shell)
{
	int		rstatus;
	char	*pwd;

	rstatus = get_pwd(prg_data, &pwd, from_shell);
	if (rstatus != 0)
		return (rstatus);
	rstatus = add_or_modify_env_element_if_exists(prg_data, "PWD", pwd);
	free(pwd);
	return (rstatus);
}

static int	set_current_directory_to_home(t_prg_data *prg_data)
{
	char	*home_dir;

	if (get_env_element_address_by_name(prg_data, "HOME") == 0)
		return (ft_fperror(*prg_data, "cd", "HOME not set"));
	home_dir = get_env_element_value_by_name(prg_data, "HOME");
	if (!home_dir)
		return (ft_perror_errno(*prg_data));
	if (chdir(home_dir) == -1)
	{
		free(home_dir);
		return (ft_perror_errno(*prg_data));
	}
	free(home_dir);
	return (0);
}

int	exec_cd_builtin(t_prg_data *prg_data, t_command *command)
{
	int	rstatus;

	if (command->args[1] == 0)
	{
		rstatus = set_current_directory_to_home(prg_data);
		if (rstatus != 0)
			return (rstatus);
	}
	else
	{
		if (chdir(command->args[1]) == -1)
			return (ft_perror_errno(*prg_data) * 0);
	}
	return (updates_env_pwd_and_oldpwd(prg_data));
}
