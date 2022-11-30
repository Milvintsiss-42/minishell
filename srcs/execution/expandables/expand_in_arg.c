/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_in_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:07:42 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/30 15:34:24 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	handle_single_quotes(
	t_prg_data *prg_data,
	t_arg_cpnt **arg_cpnts,
	char **arg,
	char **startcpnt)
{
	if (**arg == '\'')
	{
		if (!add_new_cpnt(prg_data, arg_cpnts, *startcpnt, *arg))
			return (0);
		if (!add_new_cpnt(prg_data, arg_cpnts,
				*arg + 1, ft_strchr(*arg + 1, '\'')))
			return (0);
		*arg = ft_strchr(*arg + 1, '\'') + 1;
		*startcpnt = *arg;
	}
	return (1);
}

static int	handle_expandable(
	t_prg_data *prg_data,
	t_arg_cpnt **arg_cpnts,
	char **arg,
	char **startcpnt)
{
	if (**arg == '$')
	{
		if (!add_new_cpnt(prg_data, arg_cpnts, *startcpnt, *arg))
			return (0);
		if (*(*arg + 1) == '?')
		{
			if (!add_new_cpnt_exit_status(prg_data, arg_cpnts))
				return (0);
			*arg += 2;
		}
		else
		{
			*startcpnt = ++(*arg);
			while (**arg && (ft_isalnum(**arg) || **arg == '_'))
				(*arg)++;
			if (!add_new_cpnt_from_expandable(prg_data, arg_cpnts,
					*startcpnt, *arg))
				return (0);
		}
		*startcpnt = *arg;
	}
	return (1);
}

static int	handle_double_quotes_or_0(
	t_prg_data *prg_data,
	t_arg_cpnt **arg_cpnts,
	char **arg,
	char **startcpnt)
{
	if (**arg == '\"' || !**arg)
		if (!add_new_cpnt(prg_data, arg_cpnts, *startcpnt, *arg))
			return (0);
	if (**arg == '\"')
	{
		(*arg)++;
		*startcpnt = *arg;
	}
	return (1);
}

static int	init_method_vars(
	t_prg_data *prg_data,
	t_arg_cpnt **arg_cpnts,
	t_arg_cpnt **arg_cpnts_first,
	t_bool *is_in_double_quotes)
{
	*arg_cpnts = malloc(sizeof(t_arg_cpnt));
	if (!*arg_cpnts)
	{
		ft_perror_errno(*prg_data);
		return (0);
	}
	*arg_cpnts_first = *arg_cpnts;
	(*arg_cpnts)->next = 0;
	*is_in_double_quotes = FALSE;
	return (1);
}

char	*expand_env_variables_in_arg(t_prg_data *prg_data, char *arg,
	t_bool hdoc)
{
	t_arg_cpnt	*arg_cpnts;
	t_arg_cpnt	*arg_cpnts_first;
	t_bool		is_in_double_quotes;
	char		*startcpnt;

	if (!init_method_vars(prg_data,
			&arg_cpnts, &arg_cpnts_first, &is_in_double_quotes))
		return (0);
	while (*arg)
	{
		startcpnt = arg;
		while (*arg && *arg != '\"' && (*arg != '\'' || is_in_double_quotes)
			&& (*arg != '$' || hdoc))
			arg++;
		if (!handle_single_quotes(prg_data, &arg_cpnts, &arg, &startcpnt))
			return (0);
		if (!hdoc && !handle_expandable(prg_data, &arg_cpnts, &arg, &startcpnt))
			return (0);
		if (*arg == '\"')
			is_in_double_quotes = !is_in_double_quotes;
		if (!handle_double_quotes_or_0(prg_data, &arg_cpnts, &arg, &startcpnt))
			return (0);
	}
	arg_cpnts->component = 0;
	return (build_arg(prg_data, arg_cpnts_first));
}
