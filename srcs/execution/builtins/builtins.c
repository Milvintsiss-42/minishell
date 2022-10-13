/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:11:47 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/13 21:46:50 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_builtin(t_command *command)
{
	return (ft_strncmp("cd", command->cmd, 3) == 0
		|| ft_strncmp("pwd", command->cmd, 4) == 0);
}

void	exec_builtin(t_prg_data *prg_data, t_command *command)
{
	if (ft_strncmp("cd", command->cmd, 3) == 0)
		exec_cd_builtin(prg_data, command);
	if (ft_strncmp("pwd", command->cmd, 4) == 0)
		exec_pwd_builtin(prg_data, command);
}
