/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:11:47 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/26 01:14:46 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_builtin(t_command *command)
{
	return (ft_strncmp("cd", command->args[0], 3) == 0
		|| ft_strncmp("pwd", command->args[0], 4) == 0
		|| ft_strncmp("env", command->args[0], 4) == 0
		|| ft_strncmp("echo", command->args[0], 5) == 0
		|| ft_strncmp("echo", command->args[0], 5) == 0
		|| ft_strncmp("exit", command->args[0], 5) == 0
		|| ft_strncmp("unset", command->args[0], 6) == 0
		|| ft_strncmp("export", command->args[0], 7) == 0);
}

static int	exec_command_builtin(t_prg_data *prg_data, t_command *command)
{
	if (ft_strncmp("cd", command->args[0], 3) == 0)
		return (exec_cd_builtin(prg_data, command));
	if (ft_strncmp("pwd", command->args[0], 4) == 0)
		return (exec_pwd_builtin(prg_data, command));
	if (ft_strncmp("env", command->args[0], 4) == 0)
		return (exec_env_builtin(prg_data, command));
	if (ft_strncmp("echo", command->args[0], 5) == 0)
		return (exec_echo_builtin(prg_data, command));
	if (ft_strncmp("exit", command->args[0], 5) == 0)
		return (exec_exit_builtin(prg_data, command));
	if (ft_strncmp("unset", command->args[0], 6) == 0)
		return (exec_unset_builtin(prg_data, command));
	if (ft_strncmp("export", command->args[0], 7) == 0)
		return (exec_export_builtin(prg_data, command));
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
