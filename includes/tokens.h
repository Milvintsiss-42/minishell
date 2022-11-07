/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:05:17 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/07 13:55:57 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# define STR_PIPE				"|"
# define STR_OR					"||"
# define STR_AND				"&&"
# define STR_RD_FILE			">"
# define STR_RD_STDIN			"<"
# define STR_RD_FILE_APN		">>"
# define STR_RD_STDIN_HEREDOC	"<<"
# define STR_OPEN_PRTH			"("
# define STR_CLOSE_PRTH			")"
# define STR_SPC				" "
# define STR_TAB				"\t"
# define STR_NEWLINE 			"\n"

# define SQUOTE              	'\''
# define DQUOTE               	'"'

typedef enum e_token_separator
{
	e_NONE,
	e_PIPE,
	e_RD_FILE,
	e_RD_STDIN,
	e_OPEN_PRTH,
	e_CLOSE_PRTH,
	e_SPC,
	e_TAB,
	e_NEWLINE,
	e_RD_FILE_APN,
	e_RD_STDIN_HEREDOC,
	e_OR,
	e_AND
}	t_token_separator;

#endif