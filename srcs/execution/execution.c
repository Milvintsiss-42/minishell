/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/07 21:29:44 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "unistd.h"

int	clean_execution(t_prg_data *prg_data)
{
	close_here_docs_pipes(prg_data);
	reset_commands_data_and_free(prg_data);
	return (0);
}

// If something fails during the execution of this method or the last child
// quitted unexpectedly, returns -1.
// Otherwise the returns result of the last child is returned.
int	execute(t_prg_data *prg_data)
{
	set_streams_enums(prg_data);
	if (!prompt_here_docs(prg_data))
		return (clean_execution(prg_data));
	return (execute_commands(prg_data));
}
