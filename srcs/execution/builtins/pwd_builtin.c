/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:05:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/13 04:52:44 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/// @brief
/// @param
/// @return Returns string containing path of the current directory.
/// Returns 0 on failure and sets errno accordingly.
char	*get_pwd(void)
{
	char	*buf;

	buf = malloc(sizeof(char) * 500);
	if (!buf)
		return (0);
	if (!getcwd(buf, sizeof(char) * 500))
	{
		buf = ft_realloc(buf, sizeof(char) * 500, sizeof(char) * 2048);
		if (!buf)
			return (0);
		if (!getcwd(buf, sizeof(char) * 2048))
			return (0);
	}
	return (buf);
}

int	exec_pwd_builtin(t_prg_data *prg_data, t_command *command)
{
	char	*pwd;

	(void)command;
	pwd = get_pwd();
	if (!pwd)
		return (ft_perror_errno(*prg_data));
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
