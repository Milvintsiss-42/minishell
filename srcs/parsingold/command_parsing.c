/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:02:12 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/06 19:16:24 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// returns the number of commands in the line
// handles | || && > >> < <<
// reads the line and counts the | || && > >> < <<
// doesn't count the | || && if they are in quotes
static int	get_nb_commands(char *line)
{
	int		i;
	int		amount;
	t_bool	in_squote;
	t_bool	in_dquote;
	int		len;

	i = 0;
	amount = 1;
	len = ft_strlen(line);
	in_squote = FALSE;
	in_dquote = FALSE;
	while (line[i] && i < len)
	{
		if (!in_squote && line[i] == '\"' && i - 1 >= 0 && line[i - 1] != '\\')
			in_dquote = !in_dquote;
		if (!in_dquote && line[i] == '\'' && i - 1 >= 0 && line[i - 1] != '\\')
			in_squote = !in_squote;
		if (!in_squote && !in_dquote && line[i] == '|' && ++amount)
			if (i + 1 < len && line[i + 1] == '|')
				i++;
		if (!in_squote && !in_dquote && (line[i] == '&' && i + 1 < len
				&& line[i + 1] == '&') && ++amount)
			++i;
		if (!in_squote && !in_dquote && line[i] == '>' && ++amount)
			if (i + 1 < len && line[i + 1] == '>')
				i++;
		if (!in_squote && !in_dquote && line[i] == '<' && ++amount)
			if (i + 1 < len && line[i + 1] == '<')
				i++;
		i++;
	}
	return (amount);
}

static char	**get_args(char *line, int start, int end)
{
	(void)line;
	(void)start;
	(void)end;
	return (NULL);
}

// creates a command struct based on args
// returns a pointer to a t_command
static t_command	*generate_cmd(int sep, int start, int end, char *line)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	*cmd = default_command();
	cmd->args = get_args(line, start, end);
	if (!cmd->args)
		return (NULL);
	cmd->cmd = cmd->args[-1];
	cmd->e_sep = sep;
	cmd->is_last = FALSE;
	return (cmd);
}

static t_command	*get_command(char *line, int cmd_nb)
{
	int			i;
	int			amount;
	t_bool		in_squote;
	t_bool		in_dquote;
	int			len;
	int			start;

	i = 0;
	start = i;
	amount = 1;
	len = ft_strlen(line);
	in_squote = FALSE;
	in_dquote = FALSE;
	while (line[i] && i < len)
	{
		if (!in_squote && line[i] == '\"' && i - 1 >= 0 && line[i - 1] != '\\')
			in_dquote = !in_dquote;
		if (!in_dquote && line[i] == '\'' && i - 1 >= 0 && line[i - 1] != '\\')
			in_squote = !in_squote;
		if (!in_squote && !in_dquote && line[i] == '|')
		{
			if (i + 1 < len && line[i + 1] == '|')
			{
				if (amount == cmd_nb)
					return (generate_cmd(e_OR, start, i, line));
				i++;
			}
			if (amount == cmd_nb)
				return (generate_cmd(e_PIPE, start, i, line));
			++amount;
			start = i + 1;
		}
		if (!in_squote && !in_dquote && (line[i] == '&'
				&& i + 1 < len && line[i + 1] == '&'))
		{
			if (amount == cmd_nb)
				return (generate_cmd(e_AND, start, i, line));
			i++;
			amount++;
			start = i + 1;
		}
		i++;
	}
	return (NULL);
}

// parse the line to separate each commands (seps: | || && > >> < <<)
// returns an array of commands
t_command	**get_commands(char *line)
{
	int			i;
	int			amount;
	t_command	**cmds;

	i = 0;
	amount = get_nb_commands(line);
	cmds = malloc(sizeof(t_command *) * amount);
	if (!cmds)
		return (NULL);
	while (i < amount)
	{
		cmds[i] = get_command(line, i + 1);
		if (!cmds[i])
		{
			// TODO: free all
			return (NULL);
		}
		i++;
	}
	cmds[amount - 1]->is_last = TRUE;
	return (cmds);
}
