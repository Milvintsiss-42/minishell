/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:11:47 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/08 18:40:28 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_builtin(t_command *command)
{
	return (ft_strncmp("cd", command->cmd, 3) == 0
		|| ft_strncmp("pwd", command->cmd, 4) == 0
		|| ft_strncmp("echo", command->cmd, 5) == 0
		|| ft_strncmp("exit", command->cmd, 5) == 0);
}

static int	exec_command_builtin(t_prg_data *prg_data, t_command *command)
{
	if (ft_strncmp("cd", command->cmd, 3) == 0)
		return (exec_cd_builtin(prg_data, command));
	if (ft_strncmp("pwd", command->cmd, 4) == 0)
		return (exec_pwd_builtin(prg_data, command));
	if (ft_strncmp("echo", command->cmd, 5) == 0)
		return (exec_echo_builtin(prg_data, command));
	if (ft_strncmp("exit", command->cmd, 5) == 0)
		return (exec_exit_builtin(prg_data, command));
	return (-1);
}

int	exec_builtin(t_prg_data *prg_data, t_command *command, int is_child)
{
	if (is_child)
		exit_process(prg_data, command,
			exec_command_builtin(prg_data, command));
	else
		return (exec_command_builtin(prg_data, command));
	return (-1);
}
