/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:05:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 12:49:57 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_output_len(char **env)
{
	int		i;
	size_t	output_len;

	i = 0;
	output_len = 0;
	while (env[i] != 0)
	{
		output_len += ft_strlen(env[i]) + 1;
		i++;
	}
	return (output_len);
}

static char	*join_output(char *output, char **env)
{
	size_t	cur_output_len;
	int		i;

	*output = 0;
	i = 0;
	cur_output_len = 0;
	while (env[i] != 0)
	{
		cur_output_len += ft_strlen(env[i]) + 1;
		ft_strlcat(output, env[i], cur_output_len);
		ft_strlcat(output, "\n", cur_output_len + 1);
		i++;
	}
	return (output);
}

static void	sort_env(char **env)
{
	int					i;
	unsigned long int	j;
	char				*temp;

	i = 0;
	if (!env || !env[0])
		return ;
	while (env[i + 1] != 0)
	{
		j = 0;
		while (env[i][j] == env[i + 1][j] && env[i][j] && env[i + 1][j])
			j++;
		if (env[i][j] > env[i + 1][j])
		{
			temp = env[i];
			env[i] = env [i + 1];
			env[i + 1] = temp;
			if (--i < 0)
				i = 0;
		}
		else
			i++;
	}
}

// Returns 0 on success, errno otherwise
int	get_output_from_env(t_prg_data *prg_data, char **r_output, char **env,
	t_bool alph_order)
{
	char	*output;
	char	**sorted_env;

	if (copy_env_to_heap(prg_data, &sorted_env, env) != 0)
		return (errno);
	output = malloc(sizeof(char) * (get_output_len(env) + 1));
	if (!output)
	{
		free_env(sorted_env);
		return (ft_perror_errno(*prg_data));
	}
	if (alph_order)
		sort_env(sorted_env);
	*r_output = join_output(output, sorted_env);
	free_env(sorted_env);
	return (0);
}

int	exec_env_builtin(t_prg_data *prg_data, t_command *command)
{
	char	**env;
	char	*output;

	(void)command;
	env = prg_data->env;
	if (!env)
		return (0);
	if (get_output_from_env(prg_data, &output, env, FALSE) != 0)
		return (ft_perror_errno(*prg_data));
	write(STDOUT_FILENO, output, ft_strlen(output));
	free(output);
	return (0);
}
