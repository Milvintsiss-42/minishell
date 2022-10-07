/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:06 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/07 18:13:51 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "common.h"

static void	signal_int(int signo)
{
	if (signo == SIGINT)
	{
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
