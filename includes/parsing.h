/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:59:06 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/22 16:57:24 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "common.h"
# include "tokens.h"

// ERR_CSM errors are custom errors that need arguments and to be printed with
// ft_print_fd.
// Others errors can be printed with perror.

// ex: cat <<
// ex: cat < >
// ex: cat < < infile
# define ERR_LONELY_SYMBOLS	"syntax error: One or multiple symbols are \
alone, please give them a friend"

// ex: cat << HERE < infile
// -> minishell: warning: Multiple inputs are given, "<< HERE" will be ignored.
# define ERR_CSM_MULTIPLE_INPUTS "%s: warning: Multiple inputs are given, \
\"%s\" will be ignored."

// ex: cat > outfile > outfile2
// -> minishell: warning: Multiple outputs are given, "> outfile" will be
// ignored.
# define ERR_CSM_MULTIPLE_OUTPUTS "%s: warning: Multiple outputs are given, \
\"%s\" will be ignored."

typedef struct s_lst_tokens
{
	char					*token;

	t_bool					is_separator;
	t_token_separator		sep;

	t_bool					is_in_parenthesis;

	t_bool					is_in_quotes;
	t_bool					does_expand;

	struct s_lst_tokens		*prev;
	struct s_lst_tokens		*next;
}				t_lst_tokens;

t_command			*parsing(t_prg_data *prog_data, char *line);
t_token_separator	is_separator(char *str);
int					validate_input(char *line);
void				*free_parsing(t_lst_tokens *tokens);
// tokeninzer/lexer into commands
t_command			*cmd_translator(t_lst_tokens *tokens, t_prg_data *prg_data);
size_t				command_nu(t_lst_tokens *tokens);
t_token_separator	is_or_and_pipe(char *str);
int					command_generator(t_command	*command, t_lst_tokens **tkns);
int					handle_files(t_token_separator sep, t_command *command,
						t_lst_tokens **tokens);
int					copy_args(char **src, char **dest);
int					add_arg( t_command *command, t_lst_tokens *tokens);
#endif
