/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:55:58 by oaarsse           #+#    #+#             */
/*   Updated: 2022/12/01 00:38:37 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	free_arg(char **arg)
{
	char	**tmp;

	if (!arg)
		return (-1);
	tmp = arg;
	while (*arg)
	{
		free(*arg);
		arg++;
	}
	free(tmp);
	return (-1);
}

int	copy_args(char **src, char **dest)
{
	size_t	i;

	if (!src || !dest)
		return (-1);
	i = 0;
	while (*src)
	{
		*dest = ft_strdup(*src);
		if (!*dest)
			return (free_arg(dest));
		i++;
		dest++;
		src++;
	}
	return (1);
}

int	add_arg(t_command *command, t_lst_tokens *tokens)
{
	size_t	len;
	char	**new_arg;

	len = 0;
	while (command->args && command->args[len] != NULL)
		len++;
	new_arg = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_arg)
		return (-1);
	new_arg[len] = ft_strdup(tokens->token);
	if (!new_arg[len])
		return (free_arg(new_arg));
	new_arg[len + 1] = NULL;
	if (!copy_args(command->args, new_arg))
		return (free_arg(command->args));
	free_arg(command->args);
	command->args = new_arg;
	return (1);
}
