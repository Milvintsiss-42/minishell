/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:03:52 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/07 21:46:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "common.h"

// ERR_CSM errors are custom errors that need arguments and to be printed with
// ft_print_fd.
// Others errors can be printed with perror.
# define ERR_CMD_NOT_FOUND				"Command not found"
# define ERR_CSM_EOF_IN_HERE_DOC		"%s: warning: here-document at line %d\
 delimited by end-of-file (wanted `%s')\n"

void		set_streams_enums(t_prg_data *prg_data);

int			execute_commands(t_prg_data *prg_data);
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

int			exec_builtin(t_prg_data *prg_data, t_command *command,
				int is_child);
int			is_builtin(t_command *command);
int			exec_cd_builtin(t_prg_data *prg_data, t_command *command);
int			exec_pwd_builtin(t_prg_data *prg_data, t_command *command);

#endif
