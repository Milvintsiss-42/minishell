/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_command_separator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:05:27 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/19 21:58:47 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_token_separator	is_or_and_pipe(char *str)
{
	if (str && *str && *(str + 1) && ft_strncmp(str, STR_OR, 2) == 0)
		return (e_OR);
	else if (str && *str && *(str + 1) && ft_strncmp(str, STR_AND, 2) == 0)
		return (e_AND);
	else if (str && *str && ft_strncmp(str, STR_PIPE, 1) == 0)
		return (e_PIPE);
	return (e_NONE);
}
