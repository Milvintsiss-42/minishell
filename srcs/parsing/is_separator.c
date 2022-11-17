/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:52:02 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/08 18:05:11 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokens.h"

t_token_separator	is_separator(char *str)
{
	if (str && ft_strncmp(str, STR_OR, 2) == 0)
		return (e_OR);
	else if (str && ft_strncmp(str, STR_AND, 2) == 0)
		return (e_AND);
	else if (str && ft_strncmp(str, STR_RD_FILE_APN, 2) == 0)
		return (e_RD_FILE_APN);
	else if (str && ft_strncmp(str, STR_RD_STDIN_HEREDOC, 2) == 0)
		return (e_RD_STDIN_HEREDOC);
	else if (str && ft_strncmp(str, STR_PIPE, 1) == 0)
		return (e_PIPE);
	else if (str && ft_strncmp(str, STR_RD_FILE, 1) == 0)
		return (e_RD_FILE);
	else if (str && ft_strncmp(str, STR_RD_STDIN, 1) == 0)
		return (e_RD_STDIN);
	else if (str && ft_strncmp(str, STR_OPEN_PRTH, 1) == 0)
		return (e_OPEN_PRTH);
	else if (str && ft_strncmp(str, STR_CLOSE_PRTH, 1) == 0)
		return (e_CLOSE_PRTH);
	else if (str && ft_strncmp(str, STR_SPC, 1) == 0)
		return (e_SPC);
	else if (str && ft_strncmp(str, STR_TAB, 1) == 0)
		return (e_TAB);
	else if (str && ft_strncmp(str, STR_NEWLINE, 1) == 0)
		return (e_NEWLINE);
	return (e_NONE);
}
