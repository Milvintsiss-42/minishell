/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_prg_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:44:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/09 18:50:47 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	clear_prg_data(t_prg_data *prg_data)
{
	free_env(prg_data->env);
	reset_commands_data_and_free(prg_data);
}
