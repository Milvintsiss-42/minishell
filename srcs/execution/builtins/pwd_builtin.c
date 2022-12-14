/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:05:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/01 03:44:05 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	exec_pwd_builtin(t_prg_data *prg_data, t_command *command)
{
	char	*pwd;
	int		err;

	err = 0;
	(void)command;
	if (get_env_element_address_by_name(prg_data, "PWD") == 0)
	{
		if (updates_env_pwd(prg_data, FALSE) != 0)
			return (errno);
	}
	pwd = get_env_element_value_by_name(prg_data, "PWD");
	if (!pwd)
		return (ft_perror_errno(*prg_data));
	if (printf("%s\n", pwd) < 0)
		err = ft_fperror_errno(*prg_data, "pwd");
	free(pwd);
	return (err);
}
