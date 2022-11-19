/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_modify_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:12:58 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/19 03:28:47 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/// @brief Reallocs env and adds the new element to it.
/// @param prg_data 
/// @param name New element name, should not be null.
/// @param value New element value, should not be null.
/// @return Returns 0 in case of success. Returns errno and print the
/// corresponding error otherwise.
int	add_element_to_env(t_prg_data *prg_data, char *name, char *value)
{
	char	**new_env;
	int		old_env_size;
	char	*new_element;
	int		i;

	old_env_size = get_env_size(prg_data->env);
	new_env = malloc(sizeof(char *) * (old_env_size + 2));
	if (!new_env)
		return (ft_perror_errno(*prg_data));
	i = 0;
	while (prg_data->env[i])
	{
		new_env[i] = prg_data->env[i];
		i++;
	}
	new_env[i] = 0;
	free(prg_data->env);
	prg_data->env = new_env;
	ft_vasprintf(&new_element, "%s=%s", name, value);
	if (!new_element)
		return (ft_perror_errno(*prg_data));
	prg_data->env[old_env_size] = new_element;
	prg_data->env[old_env_size + 1] = 0;
	return (0);
}

/// @brief Finds element in env and replaces his value with new_value
/// @param prg_data 
/// @param name Element name, should not be null.
/// @param new_value New element value, should not be null.
/// @return Returns 0 in case of success.
/// Returns -1 if there is no corresponding element in env.
/// Returns errno and print the corresponding error otherwise.
int	modify_value_of_env_element(t_prg_data *prg_data,
	char *name, char *new_value)
{
	char	**env_element_address;
	char	*new_element;

	env_element_address = get_env_element_address_by_name(prg_data, name);
	if (!env_element_address)
		return (-1);
	ft_vasprintf(&new_element, "%s=%s", name, new_value);
	if (!new_element)
		return (ft_perror_errno(*prg_data));
	free(*env_element_address);
	*env_element_address = new_element;
	return (0);
}

/// @brief Finds element in env and replaces his value with new_value or creates
/// element if it does not already exist.
/// @param prg_data 
/// @param name Element name, should not be null.
/// @param new_value New element value, should not be null.
/// @return Returns 0 in case of success.
/// Returns errno and print the corresponding error otherwise.
int	add_or_modify_env_element_if_exists(t_prg_data *prg_data,
	char *name, char *new_value)
{
	int	rstatus;

	rstatus = modify_value_of_env_element(prg_data, name, new_value);
	if (rstatus >= 0)
		return (rstatus);
	return (add_element_to_env(prg_data, name, new_value));
}

static void	cpy_old_env_to_new(char **new_env, char **old_env, char **to_skip)
{
	int		i;
	int		skipped;

	i = 0;
	skipped = 0;
	while (old_env[i + skipped])
	{
		if ((old_env + i + skipped) != to_skip)
		{
			new_env[i] = old_env[i + skipped];
			i++;
		}
		else
			skipped = 1;
	}
	new_env[i] = 0;
}

/// @brief Finds element in env and remove it.
/// @param prg_data
/// @param name Element name, should not be null.
/// @return Returns 0 in case of success.
/// Returns -1 if there is no corresponding element in env.
/// Returns errno and print the corresponding error otherwise.
int	remove_env_element(t_prg_data *prg_data, char *name)
{
	char	**new_env;
	char	**env_element_address;

	env_element_address = get_env_element_address_by_name(prg_data, name);
	if (!env_element_address)
		return (-1);
	new_env = malloc(sizeof(char *) * (get_env_size(prg_data->env)));
	if (!new_env)
		return (ft_perror_errno(*prg_data));
	free(*env_element_address);
	cpy_old_env_to_new(new_env, prg_data->env, env_element_address);
	free(prg_data->env);
	prg_data->env = new_env;
	return (0);
}
