/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:39:54 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/13 20:30:14 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	get_env_size(char **env)
{
	int		nb_env_elements;

	nb_env_elements = 0;
	if (!env)
		return (0);
	while (env[nb_env_elements])
		nb_env_elements++;
	return (nb_env_elements);
}

/// @brief Returns env element string address.
/// @param prg_data 
/// @param name 
/// @return Returns env element string address. Returns 0 if there is no
/// corresponding element in env.
char	**get_env_element_address_by_name(t_prg_data *prg_data, char *name)
{
	int	i;

	i = 0;
	while (prg_data->env[i])
	{
		if (ft_strncmp(prg_data->env[i], name, ft_strlen(name)) == 0
			&& prg_data->env[i][ft_strlen(name)] == '=')
			return (&prg_data->env[i]);
		i++;
	}
	return (0);
}

/// @brief Returns env element value string.
/// @param prg_data 
/// @param name 
/// @return Returns env element value string. Returns 0 if there is no
/// corresponding element in env or if malloc failed.
char	*get_env_element_value_by_name(t_prg_data *prg_data, char *name)
{
	char	*env_element;

	if (!get_env_element_address_by_name(prg_data, name))
		return (0);
	env_element = *get_env_element_address_by_name(prg_data, name);
	return (ft_strdup(ft_strchr(env_element, '=') + 1));
}
