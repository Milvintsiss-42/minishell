/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:17:52 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/14 19:54:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "unistd.h"

// Returns 0 in case of success, returns errno otherwise
int	sets_pipe_as_stdin(t_prg_data *prg_data, t_command *command)
{
	if (command->pipe_in[0] == -1)
		return (0);
	if (dup2(command->pipe_in[0], STDIN_FILENO) == -1)
		return (ft_perror_errno(*prg_data));
	return (0);
}

// Returns 0 in case of success, returns errno otherwise
int	sets_pipe_as_stdout(t_prg_data *prg_data, t_command *command)
{
	if (command->pipe_out[1] == -1)
		return (0);
	if (dup2(command->pipe_out[1], STDOUT_FILENO) == -1)
		return (ft_perror_errno(*prg_data));
	return (0);
}

void	cpy_pipe(int dst_pipe[2], int src_pipe[2])
{
	dst_pipe[0] = src_pipe[0];
	dst_pipe[1] = src_pipe[1];
}

void	close_pipe(int fds_pipe[2])
{
	if (fds_pipe[0] != -1)
		close(fds_pipe[0]);
	if (fds_pipe[1] != -1)
		close(fds_pipe[1]);
}
