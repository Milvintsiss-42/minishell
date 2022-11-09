/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:39:54 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/09 19:02:38 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_env(char **env)
{
	char	**save;

	save = env;
	if (!env)
		return ;
	while (*env)
	{
		free(*env);
		env++;
	}
	free(save);
}

static char	**copy_env_elements(char **env_cpy, char *const *env)
{
	char	**env_cpy_save;

	env_cpy_save = env_cpy;
	while (*env)
	{
		*env_cpy = ft_strdup(*env);
		if (!*env_cpy)
		{
			free_env(env_cpy);
			return (0);
		}
		env++;
		env_cpy++;
	}
	return (env_cpy_save);
}

int	copy_env_to_heap(t_prg_data *prg_data, char ***r_env_cpy, char *const *env)
{
	char	**env_cpy;
	int		nb_env_elements;

	nb_env_elements = 0;
	if (env)
		while (env[nb_env_elements])
			nb_env_elements++;
	env_cpy = malloc(sizeof(char *) * (nb_env_elements + 1));
	if (!env_cpy)
		return (ft_perror_errno(*prg_data));
	*r_env_cpy = env_cpy;
	*(env_cpy + nb_env_elements) = 0;
	if (!env)
		return (0);
	if (!copy_env_elements(env_cpy, env))
		return (ft_perror_errno(*prg_data));
	return (0);
}
