/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 02:23:51 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/24 02:24:11 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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
