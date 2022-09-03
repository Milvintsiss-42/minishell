/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:36:55 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/03 19:16:56 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

# ifndef KDEBUG
#  define KDEBUG 0
# endif
# ifndef KDEBUG_EXEC
#  define KDEBUG_EXEC 0
# endif

# define ERR_UNKNOWN			"Unknown error"

// Only last infile, outfile, or here_doc are needed, write an error to the
// stderr for each infile, outfile, here_doc who are overwrote.
// ex: cat < infile << HERE > outfile >> outfile2 | cat
// -> write an error for the first infile
// -> here_doc is passed as stdin
// -> write an error for the second outfile
// -> stdout of cat is written to outfile2 in append mode
// -> nothing is passed as stdin to the second "cat" but "cat" doesn't wait for
// input.

// Command stucture
//
// Each command needs to be initiated with default_command() method to avoid
// unitialized parameters.
typedef struct s_command
{
	char	*cmd;
	char	**args;
	char	**env;
	int		read_from_here_doc;
	char	*here_doc_limiter;
	char	*infile;
	char	*outfile;
	int		is_append_mode;
	int		pipe_in[2];
	int		pipe_out[2];
	int		is_last;
}	t_command;

// Initalized at startup
// 
// contains :
// - program name
// - environment variables
// - the history of the commands
// - amount of commands in the history
typedef struct s_prg_data
{
	const char	*bin_name;
	const char	**env;
	t_command	*commands;
	int			nb_commands;
}	t_prg_data;

int			execute(t_prg_data *prg_data);
void		test_execution(t_prg_data *prg_data);

t_command	default_command(void);

int			ft_perror(t_prg_data prg_data, const char *error_str);
int			ft_fperror(t_prg_data prg_data, const char *filename,
				const char *error_str);
int			ft_perror_errno(t_prg_data prg_data);
int			ft_fperror_errno(t_prg_data prg_data, const char *filename);

#endif