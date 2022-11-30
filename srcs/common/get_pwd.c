/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 02:23:51 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 13:45:11 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/// @brief Fill r_buf with a string containing path of the current directory.
/// @param
/// @return Returns 0 on success or corresponding errno.
int	get_pwd(t_prg_data *prg_data, char **r_buf, t_bool from_shell)
{
	*r_buf = getcwd(0, 0);
	if (!*r_buf)
	{
		if (from_shell)
		{
			ft_perror(*prg_data, "unable to identify the current directory");
			return (errno);
		}
		return (ft_perror_errno(*prg_data));
	}
	return (0);
}
