/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:52:02 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/02 16:53:17 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokens.h"

t_token_separator	is_separator(char *str)
{
	if (ft_strncmp(str, STR_OR, 2) == 0)
		return (e_OR);
	else if (ft_strncmp(str, STR_AND, 2) == 0)
		return (e_AND);
	else if (ft_strncmp(str, STR_RD_FILE_APN, 2) == 0)
		return (e_RD_FILE_APN);
	else if (ft_strncmp(str, STR_RD_STDIN_HEREDOC, 2) == 0)
		return (e_RD_STDIN_HEREDOC);
	else if (ft_strncmp(str, STR_PIPE, 1) == 0)
		return (e_PIPE);
	else if (ft_strncmp(str, STR_RD_FILE, 1) == 0)
		return (e_RD_FILE);
	else if (ft_strncmp(str, STR_RD_STDIN, 1) == 0)
		return (e_RD_STDIN);
	else if (ft_strncmp(str, STR_OPEN_PRTH, 1) == 0)
		return (e_OPEN_PRTH);
	else if (ft_strncmp(str, STR_CLOSE_PRTH, 1) == 0)
		return (e_CLOSE_PRTH);
	else if (ft_strncmp(str, STR_SPC, 1) == 0)
		return (e_SPC);
	else if (ft_strncmp(str, STR_TAB, 1) == 0)
		return (e_TAB);
	return (e_NONE);
}
