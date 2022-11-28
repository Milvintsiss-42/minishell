/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:20:47 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/28 15:42:55 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lexer.h"

t_command	*parsing(t_prg_data *prog_data, char *line)
{
	t_command			*commands;
	t_lst_tokens		*tokens;

	if (!line || *line == '\0')
		return (NULL);
	while (*line == ' ' || *line == '\t')
		line++;
	if (validate_input(line) == -1)
		return (NULL);
	tokens = tokenizer(line);
	if (!tokens)
		return (NULL);
	if (!check_syntax(tokens))
	{
		free_parsing(tokens);
		return (NULL);
	}
	tokens = lexer(tokens, prog_data);
	if (!tokens)
		return (NULL);
	commands = cmd_translator(tokens, prog_data);
	free_parsing(tokens);
	return (commands);
}
