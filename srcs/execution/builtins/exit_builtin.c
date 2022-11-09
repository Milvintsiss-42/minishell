/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:32:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/09 01:04:40 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	is_number(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	exec_exit_builtin(t_prg_data *prg_data, t_command *command)
{
	int	return_value;

	return_value = 0;
	if (command->args[1] != 0 && command->args[2] != 0)
		return (ft_fperror(*prg_data, command->cmd, ERR_TOO_MANY_ARGS));
	if (command->args[1] != 0)
	{
		if (!is_number(command->args[1]))
			return (ft_fperror(*prg_data, command->cmd,
					ERR_NUMERIC_ARG_REQUIRED));
		return_value = ft_atoi(command->args[1]);
		if ((*command->args[1] == '-' && return_value == 1)
			|| (*command->args[1] != '-' && return_value == -1))
			return (ft_fperror(*prg_data, command->cmd,
					ERR_NUMERIC_ARG_OVERFLOWING));
	}
	exit_process(prg_data, command, return_value);
	return (0);
}
