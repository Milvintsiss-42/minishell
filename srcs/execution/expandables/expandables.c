/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:06:36 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 13:26:03 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	expand_env_variables_in_redirections_files(t_prg_data *prg_data,
	t_command *command)
{
	char	*save;

	if (command->outfile)
	{
		save = command->outfile;
		command->outfile = expand_env_variables_in_arg(prg_data,
				command->outfile);
		free(save);
		if (!command->outfile)
			return (0);
	}
	if (command->infile)
	{
		save = command->infile;
		command->infile = expand_env_variables_in_arg(prg_data,
				command->infile);
		free(save);
		if (!command->infile)
			return (0);
	}
	return (1);
}

static int	free_last_args_on_error(char **arg)
{
	arg++;
	while (*arg)
	{
		free(arg);
		arg = 0;
		arg++;
	}
	return (0);
}

int	expand_env_variables(t_prg_data *prg_data)
{
	int		i;
	char	**arg;
	char	*arg_save;

	i = -1;
	while (++i < prg_data->nb_cmds_in_pl)
	{
		if (!expand_env_variables_in_redirections_files(prg_data,
				&prg_data->cur_pipeline[i]))
			return (0);
		arg = prg_data->cur_pipeline[i].args;
		while (arg && *arg)
		{
			arg_save = *arg;
			*arg = expand_env_variables_in_arg(prg_data, *arg);
			free(arg_save);
			if (!*arg)
				return (free_last_args_on_error(arg));
			arg++;
		}
	}
	return (1);
}
