/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:40:31 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/30 01:06:56 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "common.h"

static void	signal_int_heredoc(int signo)
{
	if (signo == SIGINT)
	{
		g_last_exit_status = -42;
		close(0);
	}
}

void	ft_signal_handler_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_int_heredoc);
}
