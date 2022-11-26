/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:45:58 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/26 03:19:33 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// Returns a (char *) set to 0 for conveniance
static char	*free_cpnts(t_arg_cpnt *arg_cpnts)
{
	t_arg_cpnt	*to_free;

	while (arg_cpnts)
	{
		to_free = arg_cpnts;
		arg_cpnts = arg_cpnts->next;
		free(to_free->component);
		free(to_free);
	}
	return (0);
}

static size_t	get_arg_len(t_arg_cpnt *arg_cpnts)
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

static char	*build_arg(t_prg_data *prg_data, t_arg_cpnt *arg_cpnts)
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

// Returns a (char *) for conveniance, returns 0 on error and 1 on success.
static char	*add_new_cpnt(t_prg_data *prg_data, t_arg_cpnt **arg_cpnts,
	char *new_cpnt_start, char *new_cpnt_end)
{
	(*arg_cpnts)->component
		= ft_strndup(new_cpnt_start, new_cpnt_end - new_cpnt_start);
	if (!(*arg_cpnts)->component)
	{
		ft_perror_errno(*prg_data);
		return (free_cpnts(*arg_cpnts));
	}
	(*arg_cpnts)->next = malloc(sizeof(t_arg_cpnt));
	if (!(*arg_cpnts)->next)
	{
		ft_perror_errno(*prg_data);
		return (free_cpnts(*arg_cpnts));
	}
	(*arg_cpnts)->next->next = 0;
	*arg_cpnts = (*arg_cpnts)->next;
	return ((char *)1);
}

// Returns a (char *) for conveniance, returns 0 on error and 1 on success.
static char	*add_new_cpnt_from_expandable(
	t_prg_data *prg_data,
	t_arg_cpnt **arg_cpnts,
	char *expandable_name_start,
	char *expandable_name_end)
{
	char	*variable_name;
	char	*variable_value;

	variable_name = ft_strndup(
			expandable_name_start, expandable_name_end - expandable_name_start);
	if (!variable_name)
	{
		(*arg_cpnts)->component = 0;
		ft_perror_errno(*prg_data);
		return (free_cpnts(*arg_cpnts));
	}
	variable_value = get_env_element_value_by_name(prg_data, variable_name);
	free(variable_name);
	(*arg_cpnts)->component = variable_value;
	(*arg_cpnts)->next = malloc(sizeof(t_arg_cpnt));
	if (!(*arg_cpnts)->next)
	{
		ft_perror_errno(*prg_data);
		return (free_cpnts(*arg_cpnts));
	}
	(*arg_cpnts)->next->next = 0;
	*arg_cpnts = (*arg_cpnts)->next;
	return ((char *)1);
}

// Returns a (char *) for conveniance, returns 0 on error and 1 on success.
static char	*add_new_cpnt_exit_status(t_prg_data *prg_data,
	t_arg_cpnt **arg_cpnts)
{
	(*arg_cpnts)->component = ft_itoa(g_last_exit_status);
	(*arg_cpnts)->next = malloc(sizeof(t_arg_cpnt));
	if (!(*arg_cpnts)->next)
	{
		ft_perror_errno(*prg_data);
		return (free_cpnts(*arg_cpnts));
	}
	(*arg_cpnts)->next->next = 0;
	*arg_cpnts = (*arg_cpnts)->next;
	return ((char *)1);
}

static char	*expand_env_variables_in_arg(t_prg_data *prg_data, char *arg)
{
	t_arg_cpnt	*arg_cpnts;
	t_arg_cpnt	*arg_cpnts_first;
	int			is_in_double_quotes;
	char		*startcpnt;

	arg_cpnts = malloc(sizeof(t_arg_cpnt));
	if (!arg_cpnts)
	{
		ft_perror_errno(*prg_data);
		return (0);
	}
	arg_cpnts_first = arg_cpnts;
	arg_cpnts->next = 0;
	is_in_double_quotes = 0;
	while (*arg)
	{
		startcpnt = arg;
		while (*arg && *arg != '\"' && (*arg != '\'' || is_in_double_quotes)
			&& *arg != '$')
			arg++;
		if (*arg == '$')
		{
			if (!add_new_cpnt(prg_data, &arg_cpnts, startcpnt, arg))
				return (0);
			if (*(arg + 1) == '?')
			{
				if (!add_new_cpnt_exit_status(prg_data, &arg_cpnts))
					return (0);
				arg += 2;
			}
			else
			{
				startcpnt = ++arg;
				while (*arg && (ft_isalnum(*arg) || *arg == '_'))
					arg++;
				if (!add_new_cpnt_from_expandable(prg_data, &arg_cpnts,
						startcpnt, arg))
					return (0);
			}
		}
		else if (*arg == '\'')
		{
			if (!add_new_cpnt(prg_data, &arg_cpnts, startcpnt, arg))
				return (0);
			if (!add_new_cpnt(prg_data, &arg_cpnts,
					arg + 1, ft_strchr(arg + 1, '\'')))
				return (0);
			arg = ft_strchr(arg + 1, '\'') + 1;
		}
		else if (*arg == '\"')
		{
			if (!add_new_cpnt(prg_data, &arg_cpnts, startcpnt, arg))
				return (0);
			is_in_double_quotes = !is_in_double_quotes;
			arg++;
		}
		else if (!*arg && !add_new_cpnt(prg_data, &arg_cpnts, startcpnt, arg))
			return (0);
	}
	arg_cpnts->component = 0;
	return (build_arg(prg_data, arg_cpnts_first));
}

int	expand_env_variables_in_args(t_prg_data *prg_data)
{
	int		i;
	char	**arg;
	char	*arg_save;

	i = -1;
	while (++i < prg_data->nb_cmds_in_pl)
	{
		arg = prg_data->cur_pipeline[i].args;
		while (*arg)
		{
			arg_save = *arg;
			*arg = expand_env_variables_in_arg(prg_data, *arg);
			free(arg_save);
			if (!*arg) // TODO: free args after current because it will stop at this 0
				return (0);
			arg++;
		}
	}
	return (1);
}
