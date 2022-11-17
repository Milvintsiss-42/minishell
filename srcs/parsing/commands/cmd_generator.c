/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:30:26 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/17 17:37:41 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	handle_files(t_token_separator sep, t_command *command,
		t_lst_tokens *tokens)
{
	if (sep == e_RD_FILE || sep == e_RD_FILE_APN)
	{
		if (sep == e_RD_FILE_APN)
			command->is_append_mode = TRUE;
		if (command->outfile)
			free(command->outfile);
		command->outfile = ft_strdup(tokens->next->token);
		if (!command->outfile)
			return (1);
	}
	else if (sep == e_RD_STDIN)
	{
		if (command->infile)
			free(command->infile);
		command->infile = ft_strdup(tokens->next->token);
		if (!command->infile)
			return (1);
	}
	else if (sep == e_RD_STDIN_HEREDOC)
	{
		if (command->here_doc_limiter)
			free(command->here_doc_limiter);
		command->here_doc_limiter = ft_strdup(tokens->next->token);
		if (!command->here_doc_limiter)
			return (1);
	}
	return (-1);
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

int	command_generator(t_command	*command, t_lst_tokens **tokens)
{
	t_token_separator	sep;

	command->cmd = ft_strdup((*tokens)->token);
	if (!command->cmd)
		return (1);
	command->args = (char **)malloc(sizeof(char *) * 2);
	if (!command->args)
		return (1);
	command->args[0] = ft_strdup((*tokens)->token);
	if (!command->args[0])
		return (1);
	command->args[1] = NULL;
	*tokens = (*tokens)->next;
	sep = 0;
	while (*tokens)
	{
		sep = is_separator((*tokens)->token);
		if (sep == e_OR || sep == e_AND || sep == e_PIPE)
			break ;
		else if (sep == e_NONE)
			add_arg(command, *tokens);
		if (!handle_files(sep, command, *tokens))
			return (-1);
		(*tokens) = (*tokens)->next;
	}
	command->e_sep = sep;
	if (sep == e_OR || sep == e_AND || sep == e_PIPE)
		(*tokens) = (*tokens)->next;
	return (1);
}
