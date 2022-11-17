/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:26 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/17 18:03:40 by oaarsse          ###   ########.fr       */
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

static int	copy_args(char **src, char **dest)
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

static int	add_arg( t_command *command,
		t_lst_tokens *tokens)
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

static int	initalize_cmd(t_command	*command, t_lst_tokens **tokens)
{
	command->cmd = ft_strdup((*tokens)->token);
	if (!command->cmd)
		return (-1);
	command->args = (char **)malloc(sizeof(char *) * 2);
	if (!command->args)
		return (-1);
	command->args[0] = ft_strdup((*tokens)->token);
	if (!command->args[0])
		return (-1);
	command->args[1] = NULL;
	*tokens = (*tokens)->next;
	return (1);
}

int	command_generator(t_command	*command, t_lst_tokens **tokens)
{
	t_token_separator	sep;

	if (!initalize_cmd(command, tokens))
		return (-1);
	sep = 0;
	while (*tokens)
	{
		sep = is_separator((*tokens)->token);
		if (sep == e_OR || sep == e_AND || sep == e_PIPE)
			break ;
		else if (sep == e_NONE)
			add_arg(command, *tokens);
		else
		{
			if (handle_files(sep, command, tokens) == -1)
				return (-1);
		}
		(*tokens) = (*tokens)->next;
	}
	if (sep == e_OR || sep == e_AND || sep == e_PIPE)
	{
		command->e_sep = sep;
		(*tokens) = (*tokens)->next;
	}
	return (1);
}
