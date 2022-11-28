/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:13:35 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/28 18:13:54 by ple-stra         ###   ########.fr       */
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

char	*build_arg(t_prg_data *prg_data, t_arg_cpnt *arg_cpnts)
{
	char		*arg;
	char		*arg_save;
	t_arg_cpnt	*arg_cpnts_save;
	char		*cpnt;
	size_t		t_len;

	arg_cpnts_save = arg_cpnts;
	t_len = get_arg_len(arg_cpnts);
	arg = malloc(sizeof(char) * (t_len + 1));
	if (!arg)
	{
		ft_perror_errno(*prg_data);
		free_cpnts(arg_cpnts_save);
	}
	arg_save = arg;
	while (arg_cpnts)
	{
		cpnt = arg_cpnts->component;
		while (cpnt && *cpnt)
			*arg++ = *cpnt++;
		arg_cpnts = arg_cpnts->next;
	}
	*arg = 0;
	free_cpnts(arg_cpnts_save);
	return (arg_save);
}
