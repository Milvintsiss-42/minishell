/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/07 21:34:49 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	exec_cd_builtin(t_prg_data *prg_data, t_command *command)
{
	(void)prg_data;
	if (chdir(command->args[1]) == -1)
		return (ft_perror_errno(*prg_data) * 0);
	return (0);
}
