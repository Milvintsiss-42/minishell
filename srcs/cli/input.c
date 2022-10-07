/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:18 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/07 17:44:17 by oaarsse          ###   ########.fr       */
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
		// TODO: find way to print prompt again
		ft_putstr_fd("\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		return ;
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
	// signal(SIGQUIT, SIG_IGN);
	while (TRUE)
	{
		line = readline("\n> ");
		if (!line)
			continue; //TODO: exit properly
		if (ft_strlen(line) > 0)
			add_history(line); //TODO: free history at the end -> rl_clear_history();
		(void)data;
		(void)cmds;
		//TODO: parsing
		//TODO: execution
		//TODO: free allocated stuffs
		free(line);
	}
}
