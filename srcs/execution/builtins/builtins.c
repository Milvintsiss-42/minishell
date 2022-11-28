/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:11:47 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/29 00:56:48 by ple-stra         ###   ########.fr       */
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

static int	save_std_streams(t_prg_data *prg_data,
	int *stdin_save, int *stdout_save)
{
	*stdin_save = dup(STDIN_FILENO);
	*stdout_save = dup(STDOUT_FILENO);
	if (*stdin_save == -1 || *stdout_save == -1)
		return (ft_perror_errno(*prg_data));
	return (0);
}

static int	rst_std_streams(t_prg_data *prg_data,
	int stdin_save, int stdout_save)
{
	stdin_save = dup2(stdin_save, STDIN_FILENO);
	stdout_save = dup2(stdout_save, STDOUT_FILENO);
	if (stdin_save == -1 || stdout_save == -1)
		return (ft_perror_errno(*prg_data));
	return (0);
}

int	exec_builtin(t_prg_data *prg_data, t_command *command, int is_child)
{
	int	err;
	int	stdin_save;
	int	stdout_save;

	err = 0;
	if (is_child)
		exit_process(prg_data, command,
			exec_command_builtin(prg_data, command));
	else
	{
		err = save_std_streams(prg_data, &stdin_save, &stdout_save);
		if (err != 0)
			return (err);
		if (command->e_stdin == stream_REDIR)
			err = set_infile_as_stdin(prg_data, command);
		if (err != 0)
			return (err);
		if (command->e_stdout == stream_REDIR)
			err = set_outfile_as_stdout(prg_data, command);
		if (err != 0)
			return (rst_std_streams(prg_data, stdin_save, stdout_save) && err);
		err = exec_command_builtin(prg_data, command);
		return (rst_std_streams(prg_data, stdin_save, stdout_save));
	}
	return (-1);
}
