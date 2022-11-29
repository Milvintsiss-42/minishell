/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:10:48 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/29 22:35:07 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>

void	ft_signal_handler(void);
void	ft_signal_handler_heredoc(void);
void	ft_signal_handler_child(void);
void	ft_signal_handler_default(void);
#endif
