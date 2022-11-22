/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:26 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/22 16:59:46 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	initalize_cmd(t_command	*command, t_lst_tokens **tokens)
{
	if (is_separator((*tokens)->token) == e_OPEN_PRTH)
	{
		command->is_opening_parenthesis = 1;
		*tokens = (*tokens)->next;
	}
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

static int	final_touch(t_command	*command, t_lst_tokens **tokens,
		t_token_separator sep)
{
	if (sep == e_OR || sep == e_AND || sep == e_PIPE || sep == e_CLOSE_PRTH)
	{
		if (sep == e_CLOSE_PRTH)
			command->is_closing_parenthesis = 1;
		else
			command->e_sep = sep;
		if (*tokens)
			(*tokens) = (*tokens)->next;
	}
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
			if (handle_files(sep, command, tokens) == -1)
				return (-1);
		(*tokens) = (*tokens)->next;
	}
	return (final_touch(command, tokens, sep));
}
