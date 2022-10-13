/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:44:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/13 17:20:56 by ple-stra         ###   ########.fr       */
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

int	prompt_here_docs(t_prg_data *prg_data)
{
	int	i;

	i = -1;
	while (++i < prg_data->nb_commands)
		if (prg_data->commands[i].e_stdin == stream_HERE_DOC
			&& !prompt_here_doc(prg_data, &prg_data->commands[i]))
			return (0);
	return (1);
}

// If something fails during the execution of this method or the last child
// quitted unexpectedly, returns -1.
// Otherwise the returns result of the last child is returned.
int	execute(t_prg_data *prg_data)
{
	int	return_result;

	set_streams_enums(prg_data);
	if (!prompt_here_docs(prg_data))
		return (clean_execution(prg_data));
	if (!launch_childs(prg_data))
		return (clean_execution(prg_data));
	return_result = wait_for_childs_to_finish(prg_data);
	clean_execution(prg_data);
	return (return_result);
}
