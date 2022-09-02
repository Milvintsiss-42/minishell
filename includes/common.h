/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:36:55 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/02 14:51:46 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

// Only last infile, outfile, or here_doc are needed, write an error to the
// stderr for each infile, outfile, here_doc who are overwrote.
// ex: cat < infile << HERE > outfile >> outfile2 | cat
// -> write an error for the first infile
// -> here_doc is passed as stdin
// -> write an error for the second outfile
// -> stdout of cat is written to outfile2 in append mode
// -> nothing is passed as stdin to the second "cat" but "cat" doesn't wait for
// input.
// 
// Each command needs to be initiated with default_command() method to avoid
// unitialized parameters.
typedef struct s_command
{
	const char	*cmd;
	const char	**args;
	const char	**env;
	int			read_from_here_doc;
	const char	*here_doc_limiter;
	const char	*infile;
	const char	*outfile;
	int			is_append_mode;
	int			pipe_in[2];
	int			pipe_out[2];
	int			is_last;
}	t_command;

typedef struct s_prg_data
{
	const char	*bin_name;
	const char	**env;
	t_command	*commands;
	int			nb_commands;	
}	t_prg_data;

t_command			default_command(void);

#endif