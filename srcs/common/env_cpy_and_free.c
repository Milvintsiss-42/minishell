/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cpy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:01:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/01 03:17:08 by ple-stra         ###   ########.fr       */
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

int	copy_env_to_heap(t_prg_data *prg_data, char ***r_env_cpy, char *const *env)
{
	char	**env_cpy;

	env_cpy = malloc(sizeof(char *) * (get_env_size((char **)env) + 1));
	if (!env_cpy)
		return (ft_perror_errno(*prg_data));
	*r_env_cpy = env_cpy;
	*(env_cpy + get_env_size((char **)env)) = 0;
	if (!env)
		return (0);
	while (*env)
	{
		*env_cpy = ft_strdup(*env);
		if (!*env_cpy)
		{
			free_env(*r_env_cpy);
			return (ft_perror_errno(*prg_data));
		}
		env++;
		env_cpy++;
	}
	return (0);
}
