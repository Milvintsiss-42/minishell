/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:13:35 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/22 19:53:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	reset_commands_data_and_free(t_prg_data *prg_data)
{
	free_commands(prg_data->commands, prg_data->nb_commands);
	prg_data->commands = 0;
	prg_data->nb_commands = 0;
}

void	free_commands(t_command *commands, int nb_commands)
{
	int	i;

	i = -1;
	while (++i < nb_commands)
	{
		free_command_elements(commands[i]);
	}
	free(commands);
}

void	free_command_elements(t_command command)
{
	char	**args;

	if (command.cmd)
		free(command.cmd);
	args = command.args;
	while (args && *args)
		free(*args++);
	free(command.args);
	if (command.is_expandable)
		free(command.is_expandable);
	if (command.here_doc_limiter)
		free(command.here_doc_limiter);
	if (command.infile)
		free(command.infile);
	if (command.outfile)
		free(command.outfile);
}
