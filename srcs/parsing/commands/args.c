/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:55:58 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/23 17:45:08 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	copy_is_expandable(t_command *command, t_lst_tokens *tokens, size_t len)
{
	t_bool	*new_val;

	printf("DEBUG LEN: %ld\n", len);
	new_val = malloc(sizeof(t_bool) * (len + 1));
	if (!new_val)
		return (-1);
	new_val[len] = tokens->does_expand;
	while (len--)
		new_val[len] = command->is_expandable[len];
	free(command->is_expandable);
	command->is_expandable = new_val;
	return (1);
}

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
	if (copy_is_expandable(command, tokens, len) == -1)
		return (-1);
	return (1);
}
