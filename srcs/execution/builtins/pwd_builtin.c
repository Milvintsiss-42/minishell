/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:05:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/07 21:34:59 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	exec_pwd_builtin(t_prg_data *prg_data, t_command *command)
{
	char	*buf;

	(void)command;
	buf = malloc(sizeof(char) * 500);
	if (!getcwd(buf, sizeof(char) * 500))
	{
		buf = ft_realloc(buf, sizeof(char) * 2048);
		if (!getcwd(buf, sizeof(char) * 2048))
			return (ft_perror_errno(*prg_data) * 0);
	}
	printf("%s\n", buf);
	return (0);
}
