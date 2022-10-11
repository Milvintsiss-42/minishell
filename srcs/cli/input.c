/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:18 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/11 13:38:32 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"
#include "cli.h"
#include "signals.h"

// ask indefinitely for a command
// each command input is parsed and executed
//TODO: listen for signals CTRL + D or C or /
void	ft_loop_input(t_prg_data *data)
{
	char		*line;
	t_command	*cmd;

	ft_signal_handler();
	while (TRUE)
	{
		line = readline("> ");
		if (!line)
		{
			// CTRL + D case
			printf("exit\n");
			exit(0); // TODO: handle exit + clean
		}
		if (ft_strlen(line) > 0)
			add_history(line); //TODO: free history at the end -> rl_clear_history();
		while (TRUE)
		{
			cmd = parsing(data, line); //TODO: parsing
			if (!cmd)
				break ;
			//TODO: execution
			free(cmd); //TODO: free allocated stuffs
		}
		free(line); //TODO: free allocated stuffs
	}
}
