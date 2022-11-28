/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/28 19:51:59 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "unistd.h"

int	clean_execution(t_prg_data *prg_data)
{
	close_here_docs_pipes(prg_data);
	reset_commands_data_and_free(prg_data);
	return (0);
}

static int	get_nb_commands(t_command *commands, int nb_max)
{
	int	nb;

	nb = 0;
	while (++nb < nb_max)
	{
		if (commands[nb - 1].e_sep == e_AND || commands[nb - 1].e_sep == e_OR)
			return (nb);
	}
	return (nb);
}

static int	execute_pipeline(t_prg_data *prg_data, int index, int *ret_v,
	t_bool *is_in_parenthesis)
{
	if (index == 0
		|| prg_data->commands[index - 1].e_sep == e_PIPE
		|| prg_data->commands[index - 1].e_sep == e_NONE
		|| prg_data->commands[index - 1].e_sep == e_AND
		|| (prg_data->commands[index - 1].e_sep == e_OR && *ret_v != 0))
	{
		if (index != 0 && prg_data->commands[index - 1].e_sep == e_OR
			&& prg_data->commands[index].is_opening_parenthesis
			&& !(prg_data->commands[index].is_closing_parenthesis))
			*is_in_parenthesis = TRUE;
		prg_data->cur_pipeline = &prg_data->commands[index];
		prg_data->nb_cmds_in_pl = get_nb_commands(
				prg_data->cur_pipeline, prg_data->nb_commands - index);
		if (!expand_env_variables_in_args(prg_data))
			return (0);
		*ret_v = execute_pipeline_commands(prg_data);
		g_last_exit_status = *ret_v;
		if (*ret_v == -1)
			return (0);
	}
	return (1);
}

int	execute(t_prg_data *prg_dt)
{
	int		i;
	int		ret_v;
	t_bool	is_in_parenthesis;

	i = 0;
	ret_v = 0;
	is_in_parenthesis = FALSE;
	set_streams_enums(prg_dt);
	if (!prompt_here_docs(prg_dt))
		return (clean_execution(prg_dt) - 1);
	while (i < prg_dt->nb_commands)
	{
		if (i != 0
			&& prg_dt->commands[i - 1].e_sep == e_AND && ret_v != 0)
		{
			if (!is_in_parenthesis)
				break ;
			while (i < prg_dt->nb_commands
				&& !prg_dt->commands[i - 1].is_closing_parenthesis)
				i++;
			is_in_parenthesis = FALSE;
		}
		if (!execute_pipeline(prg_dt, i, &ret_v, &is_in_parenthesis))
			break ;
		while (i < prg_dt->nb_commands && prg_dt->commands[i].e_sep == e_PIPE)
			i++;
		i++;
	}
	clean_execution(prg_dt);
	return (ret_v);
}
