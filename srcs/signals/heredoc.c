/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:40:31 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/29 22:40:51 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "common.h"

static void	signal_int_heredoc(int signo)
{
	if (signo == SIGINT)
	{
		signal(SIGINT, SIG_IGN);
		g_last_exit_status = 130;
		close(0);
		return ;
	}
}

void	ft_signal_handler_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_int_heredoc);
}
