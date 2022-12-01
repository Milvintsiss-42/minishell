/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:13:35 by ple-stra          #+#    #+#             */
/*   Updated: 2022/12/01 02:53:05 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

size_t	get_arg_len(t_arg_cpnt *arg_cpnts)
{
	size_t		t_len;

	t_len = 0;
	while (arg_cpnts)
	{
		if (arg_cpnts->component)
			t_len += ft_strlen(arg_cpnts->component);
		arg_cpnts = arg_cpnts->next;
	}
	return (t_len);
}

static void	cpy_components_to_arg(t_arg_cpnt *arg_cpnts, char *arg)
{
	char	*cpnt;

	while (arg_cpnts)
	{
		cpnt = arg_cpnts->component;
		while (cpnt && *cpnt)
			*arg++ = *cpnt++;
		arg_cpnts = arg_cpnts->next;
	}
	*arg = 0;
}

char	*build_arg(t_prg_data *prg_data, t_arg_cpnt *arg_cpnts)
{
	char		*arg;
	size_t		t_len;

	t_len = get_arg_len(arg_cpnts);
	arg = malloc(sizeof(char) * (t_len + 1));
	if (!arg)
	{
		free_cpnts(arg_cpnts);
		ft_perror_errno(*prg_data);
		return (0);
	}
	cpy_components_to_arg(arg_cpnts, arg);
	free_cpnts(arg_cpnts);
	return (arg);
}
