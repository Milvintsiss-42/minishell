/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:15:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/20 06:45:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	create_and_cpy_last_pipe(t_prg_data *prg_data, int index)
{
	if (index != 0)
		cpy_pipe(prg_data->cur_pipeline[index].pipe_in,
			prg_data->cur_pipeline[index - 1].pipe_out);
	if (index != prg_data->nb_cmds_in_pl - 1)
		if (pipe(prg_data->cur_pipeline[index].pipe_out) == -1)
			return (ft_perror_errno(*prg_data) * 0);
	return (1);
}

static void	close_stdin_pipes(t_command *command, int is_first_command)
{
	if (command->e_stdin == stream_HERE_DOC)
		close_pipe(command->here_doc_pipe);
	if (!is_first_command)
		close_pipe(command->pipe_in);
}

int	launch_childs(t_prg_data *prg_data)
{
	int	i;

	i = -1;
	while (++i < prg_data->nb_cmds_in_pl)
	{
		if (!create_and_cpy_last_pipe(prg_data, i))
			return (0);
		prg_data->cur_pipeline[i].pid = fork();
		if (prg_data->cur_pipeline[i].pid < 0)
			return (ft_perror_errno(*prg_data) * 0);
		if (prg_data->cur_pipeline[i].pid == 0)
		{
			launch_child(prg_data, &prg_data->cur_pipeline[i]);
			break ;
		}
		close_stdin_pipes(&prg_data->cur_pipeline[i], i == 0);
	}
	return (1);
}

int	execute_pipeline_commands(t_prg_data *prg_data)
{
	int	return_result;

	if (prg_data->nb_cmds_in_pl == 1 && is_builtin(&prg_data->cur_pipeline[0]))
		return_result = exec_builtin(prg_data, &prg_data->cur_pipeline[0], 0);
	else
	{
		if (!launch_childs(prg_data))
			return (-1);
		return_result = wait_for_childs_to_finish(prg_data);
	}
	return (return_result);
}
