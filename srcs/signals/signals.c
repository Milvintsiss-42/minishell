/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:06 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/28 19:23:57 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "common.h"

static void	signal_int(int signo)
{
	if (signo == SIGINT)
	{
		g_last_exit_status = 130;
		ft_putstr_fd("\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}

void	ft_signal_handler(void)
{
	signal(SIGINT, signal_int);
	signal(SIGQUIT, SIG_IGN);
}

static void	signal_int_heredoc(int signo)
{
	if (signo == SIGINT)
	{
		g_last_exit_status = 130;
		close(0);
		return ;
	}
}

static void	signal_quit_heredoc(int signo)
{
	if (signo == SIGQUIT)
	{
		signal(SIGQUIT, SIG_IGN);
	}
}

void	ft_signal_handler_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_int_heredoc);
}
