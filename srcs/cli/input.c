/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:18 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/07 15:46:21 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"
#include "cli.h"

//TODO: handle if command is running
//TODO: listen for signals CTRL + D or C or /
static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		exit(0); // TODO: handle exit and free everything
		signal(SIGINT, signal_handler);
	}
}

// ask indefinitely for a command
// each command input is parsed and executed
//TODO: listen for signals CTRL + D or C or /
void	ft_loop_input(t_prg_data *data)
{
	char		*line;
	t_command	**cmds;

	signal(SIGINT, signal_handler);
	while (TRUE)
	{
		line = readline("> ");
		//TODO: HANDLE ERROR if line is NULL
		//TODO: add command to history
		if (ft_strlen(line) > 0)
			add_history(line);
		(void)data;
		(void)cmds;
		// cmds = parsing(data, line);
		// if (!cmds)
		// 	continue ; //TODO: handle error
		//TODO: execution
		//TODO: free allocated stuffs
		free(line);
	}
}
