/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:36:55 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/26 01:12:38 by ple-stra         ###   ########.fr       */
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

# include "tokens.h"

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
	char				**args;
	t_bool				*is_expandable;
	t_token_separator	e_sep;
	t_bool				is_opening_parenthesis;
	t_bool				is_closing_parenthesis;
	t_stream			e_stdin;
	t_stream			e_stdout;
	char				*here_doc_limiter;
	int					here_doc_pipe[2];
	char				*infile;
	char				*outfile;
	t_bool				is_append_mode;
	int					pipe_in[2];
	int					pipe_out[2];
	pid_t				pid;
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
	char		*bin_name;
	char		**env;
	t_command	*commands;
	int			nb_commands;

	t_command	*cur_pipeline;
	int			nb_cmds_in_pl;

	char		**history;
	int			len_history;
}	t_prg_data;

int				g_last_exit_status;

int			execute(t_prg_data *prg_data);
void		clear_prg_data(t_prg_data *prg_data);

int			test_execution(t_prg_data *prg_data);
int			test_execution_first_pipeline(t_prg_data *prg_data);
int			test_execution_second_pipeline(t_prg_data *prg_data);
int			test_execution_third_pipeline(t_prg_data *prg_data);
int			test_execution_fourth_pipeline(t_prg_data *prg_data);
int			test_execution_fifth_pipeline(t_prg_data *prg_data);
int			test_execution_sixth_pipeline(t_prg_data *prg_data);
int			test_execution_export(t_prg_data *prg_data);
int			test_execution_unset(t_prg_data *prg_data);
int			test_execution_env(t_prg_data *prg_data);
int			test_execution_exit(t_prg_data *prg_data);

t_command	default_command(void);
void		reset_commands_data_and_free(t_prg_data *prg_data);
void		free_commands(t_command *commands, int nb_commands);
void		free_command_elements(t_command command);

int			ft_perror(t_prg_data prg_data, const char *error_str);
int			ft_fperror(t_prg_data prg_data, const char *filename,
				const char *error_str);
int			ft_perror_errno(t_prg_data prg_data);
int			ft_fperror_errno(t_prg_data prg_data, const char *filename);

int			get_env_size(char **env);
char		**get_env_element_address_by_name(t_prg_data *prg_data, char *name);
char		*get_env_element_value_by_name(t_prg_data *prg_data, char *name);

void		free_env(char **env);
int			copy_env_to_heap(t_prg_data *prg_data,
				char ***r_env_cpy, char *const *env);
int			add_element_to_env(t_prg_data *prg_data, char *name, char *value);
int			modify_value_of_env_element(t_prg_data *prg_data,
				char *name, char *new_value);
int			add_or_modify_env_element_if_exists(t_prg_data *prg_data,
				char *name, char *new_value);
int			remove_env_element(t_prg_data *prg_data, char *name);

int			get_absolute_path(char **abs_path, const char *r_path,
				const char *env_path);
const char	*get_path_from_env(char *const *env);
char		*ft_basename(const char *path);

char		*get_pwd(void);
int			updates_env_pwd(t_prg_data *prg_data);

int			update_shell_lvl(t_prg_data *prg_data);

#endif
