/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/08 20:46:16 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_output_len(char **args)
{
	int		i;
	size_t	output_len;

	i = 0;
	output_len = 0;
	while (args[i] != 0)
	{
		output_len += ft_strlen(args[i]) + (i != 0);
		i++;
	}
	return (output_len);
}

static char	*join_output(char *output, char **args, int add_newline)
{
	size_t	cur_output_len;
	int		i;
	size_t	arg_len;

	*output = 0;
	i = 0;
	cur_output_len = 0;
	while (args[i] != 0)
	{
		arg_len = ft_strlen(args[i]);
		cur_output_len += arg_len + (i != 0);
		if (i != 0)
			ft_strlcat(output, " ", cur_output_len + 1);
		ft_strlcat(output, args[i], cur_output_len + 1);
		i++;
	}
	if (add_newline)
		ft_strlcat(output, "\n", cur_output_len + 2);
	return (output);
}

static int	get_output_from_args(char **r_output,
		t_prg_data *prg_data, char **args, int add_newline)
{
	char	*output;

	output = malloc(sizeof(char) * (get_output_len(args) + add_newline + 1));
	if (!output)
		return (ft_perror_errno(*prg_data));
	*r_output = join_output(output, args, add_newline);
	return (0);
}

int	exec_echo_builtin(t_prg_data *prg_data, t_command *command)
{
	int		add_newline;
	char	**args;
	char	*output;
	int		err;

	add_newline = 1;
	args = command->args + 1;
	if (!args[0])
		return (0);
	if (ft_strncmp(args[0], "-n", 3) == 0)
	{
		args++;
		add_newline = 0;
	}
	err = get_output_from_args(&output, prg_data, args, add_newline);
	if (err != 0)
		return (err);
	write(1, output, ft_strlen(output));
	free(output);
	return (0);
}
