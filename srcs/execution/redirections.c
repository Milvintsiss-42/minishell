/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:09:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/12 23:36:32 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include <fcntl.h>

void	set_infile_as_stdin(t_prg_data *prg_data, t_command *command)
{
	int	fd_file;

	fd_file = open(command->infile, O_RDONLY);
	if (fd_file == -1)
		exit_process(prg_data, command,
			ft_fperror_errno(*prg_data, command->infile));
	if (dup2(fd_file, STDIN_FILENO) == -1)
	{
		close(fd_file);
		exit_process(prg_data, command, ft_perror_errno(*prg_data));
	}
	close(fd_file);
}

void	set_outfile_as_stdout(t_prg_data *prg_data, t_command *command)
{
	int	fd_file;
	int	oflag;

	if (command->is_append_mode)
		oflag = O_WRONLY | O_CREAT | O_APPEND;
	else
		oflag = O_WRONLY | O_CREAT | O_TRUNC;
	fd_file = open(command->outfile, oflag, 0644);
	if (fd_file == -1)
		exit_process(prg_data, command,
			ft_fperror_errno(*prg_data, command->outfile));
	if (dup2(fd_file, STDOUT_FILENO) == -1)
	{
		close(fd_file);
		exit_process(prg_data, command, ft_perror_errno(*prg_data));
	}
	close(fd_file);
}
