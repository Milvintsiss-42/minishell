/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:59:06 by ple-stra          #+#    #+#             */
/*   Updated: 2022/09/05 15:45:37 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "common.h"

// ERR_CSM errors are custom errors that need arguments and to be printed with
// ft_print_fd.
// Others errors can be printed with perror.

// ex: cat <<
// ex: cat < >
// ex: cat < < infile
# define ERR_LONELY_SYMBOLS	"syntax error: One or multiple symbols are\
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

t_command	*get_commands(char *line);

#endif