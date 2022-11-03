/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:20:47 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/03 16:36:09 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lexer.h"

t_command	*parsing(t_prg_data *prog_data, char *line)
{
	t_command			*commands;
	t_lst_tokens		*tokens;

	tokens = tokenizer(line);
	while (tokens)
	{
		printf("TOKENS [%s]\n", tokens->token);
		tokens = tokens->next;
	}
	commands = NULL;
	tokens = lexer(tokens, prog_data);
	//TODO: PARSE LEXER TO COMMANDS
	free_tokenizer(tokens);
	return (commands);
}
