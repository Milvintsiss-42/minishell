/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:36:55 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/30 02:41:45 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

typedef struct s_command
{
	const char	*cmd;
	const char	**args;
	const char	**env;
	int			read_from_here_doc;
	const char	*here_doc_limiter;
	const char	*infile;
	const char	*outfile;
	int			pipe_in;
	int			pipe_out;
	int			is_last;
}	t_command;

#endif