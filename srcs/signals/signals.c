/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:06 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/25 00:34:44 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "common.h"

static void	signal_int(int signo)
{
	if (signo == SIGINT)
	{
		g_last_exit_status = 1;
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
