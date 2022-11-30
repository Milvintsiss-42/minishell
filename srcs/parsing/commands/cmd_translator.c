/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_translator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:43:49 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/30 01:03:01 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	generate_cmd(t_prg_data *data,
	t_command	*command, t_lst_tokens **tokens)
{
	if (!command || !tokens || !*tokens)
		return (-1);
	*command = default_command();
	if (!command_generator(data, command, tokens))
		return (-1);
	return (1);
}

t_command	*generate_cmds(t_prg_data *data, t_lst_tokens *tokens,
	size_t len, t_command	*commands)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (!generate_cmd(data, &commands[i], &tokens))
		{
			free_commands(commands, i + 1);
			return (NULL);
		}
		i++;
	}
	return (commands);
}

t_command	*cmd_translator(t_lst_tokens *tokens, t_prg_data *prg_data)
{
	t_command	*commands;
	size_t		len;

	if (!tokens || !prg_data)
		return (NULL);
	len = command_nu(tokens);
	commands = malloc(sizeof(t_command) * (len + 1));
	if (!commands)
		return (NULL);
	commands[len] = default_command();
	prg_data->commands = generate_cmds(prg_data, tokens, len, commands);
	if (!prg_data->commands)
		return (NULL);
	prg_data->nb_commands = len;
	return (commands);
}
