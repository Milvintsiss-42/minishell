/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_prg_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:44:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/28 22:27:05 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	clear_prg_data(t_prg_data *prg_data)
{
	free(prg_data->bin_name);
	free_env(prg_data->env);
	reset_commands_data_and_free(prg_data);
	rl_clear_history();
}
