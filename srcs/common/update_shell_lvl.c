/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shell_lvl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:35:45 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/25 13:55:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	update_shell_lvl(t_prg_data *prg_data)
{
	int		shell_lvl;
	char	*shell_lvl_str;
	int		err;

	err = 0;
	if (get_env_element_address_by_name(prg_data, "SHLVL") == 0)
		shell_lvl = 1;
	else
	{
		shell_lvl_str = get_env_element_value_by_name(prg_data, "SHLVL");
		if (!shell_lvl_str)
			return (ft_perror_errno(*prg_data));
		shell_lvl = ft_atoi(shell_lvl_str) + 1;
		free(shell_lvl_str);
	}
	shell_lvl_str = ft_itoa(shell_lvl);
	if (!shell_lvl_str)
		return (ft_perror_errno(*prg_data));
	err = add_or_modify_env_element_if_exists(prg_data, "SHLVL", shell_lvl_str);
	free(shell_lvl_str);
	return (err);
}
