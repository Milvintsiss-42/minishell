/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:01:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/07 22:58:32 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_output_from_args(char **r_output,
		t_prg_data *prg_data, char **args, int add_newline)
{
	char	*output;
	size_t	output_len;
	size_t	cur_output_len;
	int		i;
	size_t	arg_len;

	i = -1;
	output_len = 0;
	while (args[++i] != 0)
		output_len += ft_strlen(args[i]);
	output = malloc(sizeof(char) * (output_len + add_newline + 1));
	if (!output)
		return (ft_perror_errno(*prg_data));
	i = -1;
	cur_output_len = 1;
	while (args[++i] != 0)
	{
		arg_len = ft_strlen(args[i]);
		cur_output_len += arg_len;
		ft_strlcat(output, args[i], cur_output_len);
	}
	if (add_newline)
		ft_strlcat(output, "\n", cur_output_len + 1);
	*r_output = output;
	return (0);
}

int	exec_echo_builtin(t_prg_data *prg_data, t_command *command)
{
	int		add_newline;
	char	**args;
	char	*output;
	int		err;

	(void)prg_data;
	add_newline = 1;
	args = command->args + 1;
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
