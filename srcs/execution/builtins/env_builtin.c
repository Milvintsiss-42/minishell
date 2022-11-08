/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:05:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/08 21:46:22 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_output_len(char *const *env)
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

static char	*join_output(char *output, char *const *env)
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

static int	get_output_from_env(char **r_output,
		t_prg_data *prg_data, char *const *env)
{
	char	*output;

	output = malloc(sizeof(char) * (get_output_len(env) + 1));
	if (!output)
		return (ft_perror_errno(*prg_data));
	*r_output = join_output(output, env);
	return (0);
}

int	exec_env_builtin(t_prg_data *prg_data, t_command *command)
{
	char *const	*env;
	char		*output;

	env = command->env;
	if (get_output_from_env(&output, prg_data, env) != 0)
		return (ft_perror_errno(*prg_data));
	write(STDOUT_FILENO, output, ft_strlen(output));
	free(output);
	return (0);
}
