/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:35 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/11 17:44:32 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>

// prints error for the program
int	ft_perror(t_prg_data prg_data, const char *error_str)
{
	ft_printf_fd(2, "%s: %s\n", prg_data.bin_name, error_str);
	return (1);
}

// prints error for the file
int	ft_fperror(t_prg_data prg_data, const char *filename, const char *error_str)
{
	ft_printf_fd(2, "%s: %s: %s\n", prg_data.bin_name, filename, error_str);
	return (1);
}

// prints error for the program
int	ft_perror_errno(t_prg_data prg_data)
{
	if (errno == 0)
		return (ft_perror(prg_data, ERR_UNKNOWN));
	perror(prg_data.bin_name);
	return (errno);
}

// prints error for the file
int	ft_fperror_errno(t_prg_data prg_data, const char *filename)
{
	if (errno == 0)
		return (ft_fperror(prg_data, filename, ERR_UNKNOWN));
	ft_printf_fd(2, "%s: %s: %s\n",
		prg_data.bin_name, filename, strerror(errno));
	return (errno);
}
