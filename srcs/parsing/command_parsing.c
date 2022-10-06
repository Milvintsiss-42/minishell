/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:43:36 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/04 14:59:45 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

// parse the line to separate each commands (seps: | || &&)
// returns an array of commands
t_command	*get_commands(char *line)
{
	int			i;
	int			amount;
	t_command	*pointer;
	t_command	*cmds;

	i = 0;
	amount = get_nb_commands(line);
	cmds = malloc(sizeof(t_command *) * amount);
	if (!cmds)
		return (NULL);
	while (i < amount)
	{
		pointer = get_command(line, i + 1);
		if (!pointer)
		{
			// TODO: free all
			return (NULL);
		}
		cmds[i] = *pointer;
		i++;
	}
	return (cmds);
}

// returns the number of commands in the line
// handles | || &&
// reads the line and counts the | || &&
// doesn't count the | || && if they are in quotes
// TODO: hanlde if there is ||| or more could make a bug
int	get_nb_commands(char *line)
{
	int		i;
	int		amount;
	int		has_quote;
	int		len;

	i = 0;
	amount = 1;
	len = ft_strlen(line);
	has_quote = 0;
	while (line[i] && i < len)
	{
		if ((line[i] == '\'' || line[i] == '\"') && line[i - 1] != '\\')
			has_quote = !has_quote;
		if (!has_quote && line[i] == '|' && ++amount)
			if (i + 1 < len && line[i + 1] == '|')
				i++;
		if (!has_quote && (line[i] == '&' && i + 1 < len && line[i + 1] == '&'))
		{
			i++;
			amount++;
		}
		i++;
	}
	return (amount);
}

t_command	*get_command(char *line, int cmd_nb)
{
	int			i;
	int			amount;
	int			has_quote;
	int			len;
	int			start;

	i = 0;
	start = i;
	amount = 1;
	len = ft_strlen(line);
	has_quote = 0;
	while (line[i] && i < len)
	{
		// TODO: handle single and double quotes separately !
		if ((line[i] == '\'' || line[i] == '\"') && line[i - 1] != '\\')
			has_quote = !has_quote;
		if (!has_quote && line[i] == '|')
		{
			if (i + 1 < len && line[i + 1] == '|')
			{
				if (amount == cmd_nb)
					return (generate_cmd(OR, start, i, line));
				i++;
			}
			if (amount == cmd_nb)
				return (generate_cmd(PIPE, start, i, line));
			++amount;
			start = i + 1;
		}
		if (!has_quote && (line[i] == '&' && i + 1 < len && line[i + 1] == '&'))
		{
			if (amount == cmd_nb)
				return (generate_cmd(AND, start, i, line));
			i++;
			amount++;
			start = i + 1;
		}
		i++;
	}
	return (NULL);
}

t_command	*generate_cmd(int sep, int start, int end, char *line)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	*cmd = default_command();
	cmd->args = get_args(line, start, end);
	cmd->cmd = cmd->args[0];
	cmd->e_sep = sep;
	// TODO: FILL THE REST
		// TODO: if < or > or << or >>, get the file name and fill the cmd->infile / cmd->outfile
	return (cmd);
}

char	**get_args(int start, int end, char *line)
{
	int		i;
	char	**args;
	bool	squote;
	bool	dquote;

	i = start;
	squote = false;
	dquote = false;
	while (line[i] && i < end)
	{
		// check if in quotes
		if (line[i] == '\"' && line[i - 1] != '\\')
			dquote = !dquote;
		if (line[i] == '\'' && line[i - 1] != '\\')
			squote = !squote;
		if (!dquote && !squote && (line[i] == '<' || line[i] == '>'))
		{
			if (i + 1 < end && (line[i + 1] == '>' || line[i + 1] == '<'))
				// ADD line and line + 1 + \0 as args
			else
				// ADD line + \0 as args
			// add the rest as args
		}
		// get each args separated on spaces if not in quotes
	}
}
