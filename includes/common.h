/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:36:55 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/13 00:10:57 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "errno.h"
# include "string.h"

# ifndef KDEBUG
#  define KDEBUG 0
# endif
# ifndef KDEBUG_EXEC
#  define KDEBUG_EXEC 0
# endif

# define ERR_UNKNOWN			"Unknown error"

# define TRUE		1
# define FALSE		0

typedef int		t_bool;
typedef enum e_streams
{
	stream_NONE,
	stream_PIPE,
	stream_HERE_DOC,
	stream_REDIR
}	t_stream;

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
	char		*cmd;
	char		**args;
	char *const	*env;
	enum		{sep_NONE, sep_OR, sep_AND} e_sep;
	t_stream	e_stdin;
	t_stream	e_stdout;
	char		*here_doc_limiter;
	char		*infile;
	char		*outfile;
	t_bool		is_append_mode;
	int			pipe_in[2];
	int			pipe_out[2];
	pid_t		pid;
	t_bool		is_last;
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
	char *const	*env;
	t_command	*commands;
	int			nb_commands;

	char		**history;
	int			len_history;

	int			last_exit_status;
}	t_prg_data;

int			execute(t_prg_data *prg_data);
int			test_execution(t_prg_data *prg_data);

t_command	default_command(void);
void		reset_commands_data_and_free(t_prg_data *prg_data);
void		free_commands(t_command *commands, int nb_commands);
void		free_command_elements(t_command command);

int			ft_perror(t_prg_data prg_data, const char *error_str);
int			ft_fperror(t_prg_data prg_data, const char *filename,
				const char *error_str);
int			ft_perror_errno(t_prg_data prg_data);
int			ft_fperror_errno(t_prg_data prg_data, const char *filename);

int			get_absolute_path(char **abs_path, const char *r_path,
				const char *env_path);
const char	*get_path_from_env(char *const *env);
const char	*ft_basename(const char *path);

#endif
