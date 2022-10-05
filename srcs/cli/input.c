/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:18 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/05 16:49:10 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

//TODO: change prompt if needed
static void	ft_display_prompt(void)
{
	ft_printf("> ");
}

//TODO: handle if command is running
//TODO: listen for signals CTRL + D or C or /
static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, signal_handler);
	}
}

// ask indefinitely for a command
// each command input is parsed and executed
//TODO: listen for signals CTRL + D or C or /
void	ft_loop_input(t_prg_data *data)
{
	char	*line;
	char	**cmds;

	signal(SIGINT, signal_handler);
	print_logo();
	while (TRUE)
	{
		ft_display_prompt();
		line = get_next_line(STDIN_FILENO);
		//TODO: HANDLE ERROR if line is NULL
		//TODO: add command to history
		cmds = parsing(data, line);
		if (!cmds)
			continue ; //TODO: handle error
		//TODO: execution
		//TODO: free allocated stuffs
	}
}
