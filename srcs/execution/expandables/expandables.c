/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:06:36 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 00:13:26 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	expand_env_variables_in_args(t_prg_data *prg_data)
{
	int		i;
	char	**arg;
	char	*arg_save;

	i = -1;
	while (++i < prg_data->nb_cmds_in_pl)
	{
		arg = prg_data->cur_pipeline[i].args;
		while (arg && *arg)
		{
			arg_save = *arg;
			*arg = expand_env_variables_in_arg(prg_data, *arg);
			free(arg_save);
			if (!*arg)
			{
				arg++;
				while (*arg)
					free(arg++);
				return (0);
			}
			arg++;
		}
	}
	return (1);
}
