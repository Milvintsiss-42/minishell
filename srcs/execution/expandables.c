/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:14:24 by oaarsse           #+#    #+#             */
/*   Updated: 2022/09/05 14:26:25 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// check for expandable values in the args
// if there is a $, check if it is a valid expandable value
// if it is, expand it by replacing the value
void	replace_expandables(t_command *cmd)
{
	int		i;

	while (cmd->args[i])
	{
		if (is_expandable(cmd->args[i]))
		{
			// TODO: expand the value
		}
		i++;
	}
	return ;
}

// check if expandable value is valid
// Not valid examples :
// echo "\$?" -> $?
// echo '$?' -> $?
// Valid examples :
// echo $?
// echo "$?"
// echo 'a' $?
int	is_expandable(char *str)
{
	return ;
}
