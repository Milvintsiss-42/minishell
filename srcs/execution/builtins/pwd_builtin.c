/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:05:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/24 02:35:47 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	exec_pwd_builtin(t_prg_data *prg_data, t_command *command)
{
	char	*pwd;

	(void)command;
	pwd = get_env_element_value_by_name(prg_data, "PWD");
	if (!pwd)
		return (ft_perror_errno(*prg_data));
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
