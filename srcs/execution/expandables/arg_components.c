/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_components.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:08:58 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/28 18:12:12 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// Returns a (char *) set to 0 for conveniance
char	*free_cpnts(t_arg_cpnt *arg_cpnts)
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

// Returns a (char *) for conveniance, returns 0 on error and 1 on success.
char	*add_new_cpnt(t_prg_data *prg_data, t_arg_cpnt **arg_cpnts,
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
char	*add_new_cpnt_from_expandable(
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
char	*add_new_cpnt_exit_status(t_prg_data *prg_data, t_arg_cpnt **arg_cpnts)
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
