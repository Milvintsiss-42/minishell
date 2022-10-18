/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:18 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/18 15:19:45 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"
#include "cli.h"
#include "signals.h"

static void	handle_parsing_exec(t_prg_data *data, char	*line)
{
	t_command	*cmds;
	int			cmd_no;

	cmd_no = 0;
	while (TRUE)
	{
		cmds = parsing(data, line, cmd_no);
		if (!cmds)
			break ;
		//TODO: execution
		free(cmds); //TODO: free each allocated stuffs
		cmd_no++;
	}
}

// ask indefinitely for a command
// each command input is parsed and executed
//TODO: listen for signals CTRL + D or C or /
void	ft_loop_input(t_prg_data *data)
{
	char		*line;

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
		handle_parsing_exec(data, line);
		free(line); //TODO: free allocated stuffs
	}
}
