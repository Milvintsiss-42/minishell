/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:56:35 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/03 19:15:12 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>
#include <sys/errno.h>

// prints error for the program
int	ft_perror(t_prg_data prg_data, const char *error_str)
{
	ft_putstr_fd(prg_data.bin_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error_str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

// prints error for the file
int	ft_fperror(t_prg_data prg_data, const char *filename, const char *error_str)
{
	ft_putstr_fd(prg_data.bin_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(error_str, 2);
	ft_putstr_fd("\n", 2);
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
	ft_putstr_fd(prg_data.bin_name, 2);
	ft_putstr_fd(": ", 2);
	perror(filename);
	return (errno);
}
