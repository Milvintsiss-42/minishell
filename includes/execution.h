/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:03:52 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 12:17:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "common.h"

// ERR_CSM errors are custom errors that need arguments and to be printed with
// ft_print_fd.
// Others errors can be printed with perror.
# define ERR_CMD_NOT_FOUND				"Command not found"
# define ERR_TOO_MANY_ARGS				"too many arguments"
# define ERR_NUMERIC_ARG_REQUIRED		"numeric argument required"
# define ERR_NUMERIC_ARG_OVERFLOWING	"numeric argument is overflowing"
# define ERR_LOCKED_ENV_VAR				"This env variable is used by shell,\
 it will be redifined later"
# define ERR_CSM_EOF_IN_HERE_DOC		"\n%s: warning: here-document at line %d\
 delimited by end-of-file (wanted `%s')\n"

typedef struct s_arg_cpnt
{
	char				*component;
	struct s_arg_cpnt	*next;
}	t_arg_cpnt;

void		set_streams_enums(t_prg_data *prg_data);

int			expand_env_variables_in_args(t_prg_data *prg_data);
char		*expand_env_variables_in_arg(t_prg_data *prg_data, char *arg);
char		*add_new_cpnt_exit_status(t_prg_data *prg_data,
				t_arg_cpnt **arg_cpnts);
char		*add_new_cpnt_from_expandable(t_prg_data *prg_data,
				t_arg_cpnt **arg_cpnts, char *expandable_name_start,
				char *expandable_name_end);
char		*add_new_cpnt(t_prg_data *prg_data, t_arg_cpnt **arg_cpnts,
				char *new_cpnt_start, char *new_cpnt_end);
char		*free_cpnts(t_arg_cpnt *arg_cpnts);
char		*build_arg(t_prg_data *prg_data, t_arg_cpnt *arg_cpnts);
size_t		get_arg_len(t_arg_cpnt *arg_cpnts);

int			execute_pipeline_commands(t_prg_data *prg_data);
void		launch_child(t_prg_data	*prg_data, t_command *command);
int			wait_for_childs_to_finish(t_prg_data *prg_data);

int			clean_execution(t_prg_data *prg_data);
void		exit_process(t_prg_data *prg_data, t_command *command, int err);

int			sets_pipe_as_stdin(t_prg_data *prg_data, t_command *command);
int			sets_pipe_as_stdout(t_prg_data *prg_data, t_command *command);
void		cpy_pipe(int dst_pipe[2], int src_pipe[2]);
void		close_pipe(int fds_pipe[2]);

int			prompt_here_docs(t_prg_data *prg_data);
int			set_here_doc_as_stdin(t_prg_data *prg_data, t_command *command);
void		close_here_docs_pipes(t_prg_data *prg_data);

int			set_infile_as_stdin(t_prg_data *prg_data, t_command *command);
int			set_outfile_as_stdout(t_prg_data *prg_data, t_command *command);

int			get_output_from_env(t_prg_data *prg_data, char **r_output,
				char **env, t_bool alph_order);

int			exec_builtin(t_prg_data *prg_data, t_command *command,
				int is_child);
int			is_builtin(t_command *command);
int			exec_cd_builtin(t_prg_data *prg_data, t_command *command);
int			exec_pwd_builtin(t_prg_data *prg_data, t_command *command);
int			exec_env_builtin(t_prg_data *prg_data, t_command *command);
int			exec_echo_builtin(t_prg_data *prg_data, t_command *command);
int			exec_exit_builtin(t_prg_data *prg_data, t_command *command);

int			exec_unset_builtin(t_prg_data *prg_data, t_command *command);
int			exec_export_builtin(t_prg_data *prg_data, t_command *command);
int			is_name_identifier_valid(char *name);
int			error_invalid_identifier(t_prg_data *prg_data, char *cmd_name);

#endif
