/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:01:00 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/17 18:01:14 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	handle_files(t_token_separator sep, t_command *command,
		t_lst_tokens **tokens)
{
	if (sep != e_RD_FILE && sep != e_RD_FILE_APN && sep != e_RD_STDIN
		&& sep != e_RD_STDIN_HEREDOC)
		return (0);
	if (sep == e_RD_FILE || sep == e_RD_FILE_APN)
	{
		if (sep == e_RD_FILE_APN)
			command->is_append_mode = TRUE;
		if (command->outfile)
			free(command->outfile);
		command->outfile = ft_strdup((*tokens)->next->token);
		if (!command->outfile)
			return (-1);
	}
	else if (sep == e_RD_STDIN)
	{
		if (command->infile)
			free(command->infile);
		command->infile = ft_strdup((*tokens)->next->token);
		if (!command->infile)
			return (-1);
	}
	else if (sep == e_RD_STDIN_HEREDOC)
	{
		if (command->here_doc_limiter)
			free(command->here_doc_limiter);
		command->here_doc_limiter = ft_strdup((*tokens)->next->token);
		if (!command->here_doc_limiter)
			return (-1);
	}
	*tokens = (*tokens)->next;
	return (1);
}