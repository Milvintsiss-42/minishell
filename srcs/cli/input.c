/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:18 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/05 16:31:32 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

//TODO: change prompt if needed
static void	ft_display_prompt(void)
{
	ft_printf("> ");
}

//TODO: handle if command is running
static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, signal_handler);
	}
}

void	ft_loop_input(s_prg_data *data)
{
	char	*line;

	signal(SIGINT, signal_handler);
	while (TRUE)
	{
		ft_display_prompt();
		line = get_next_line(STDIN_FILENO);
		//TODO: HANDLE ERROR if line is NULL
		//TODO: add parsing + execution
	}
}
