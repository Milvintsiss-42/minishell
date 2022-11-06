/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:20:47 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/03 19:16:02 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lexer.h"

t_command	*parsing(t_prg_data *prog_data, char *line)
{
	t_command			*commands;
	t_lst_tokens		*tokens;

	tokens = tokenizer(line);
	// TODO: add handling if tokens is empty (i.e only spaces were entered)
	t_lst_tokens *tmp = tokens;
	while (tmp)
	{
		printf("TOKENS [%s]\n", tmp->token);
		tmp = tmp->next;
	}
	tokens = lexer(tokens, prog_data);
	t_lst_tokens *tmp2 = tokens;
	while (tmp2)
	{
		printf("LEXER [%s]\n", tmp2->token);
		tmp2 = tmp2->next;
	}
	//TODO: PARSE LEXER TO COMMANDS
	free_tokenizer(tokens);
	commands = NULL;
	return (commands);
}
