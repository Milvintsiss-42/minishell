/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:02:12 by oaarsse           #+#    #+#             */
/*   Updated: 2022/10/19 16:34:21 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"

static void	*get_to_command(char *line, int cmd_no)
{
	int		i;
	int		amnt;
	t_bool	sqo;
	t_bool	dqo;

	i = 0;
	amnt = 1;
	sqo = FALSE;
	dqo = FALSE;
	while (line[i])
	{
		if (!sqo && line[i] == '\"')
			dqo = !dqo;
		if (!dqo && line[i] == '\'')
			sqo = !sqo;
		if (!sqo && !dqo && line[i] == '|' && line[i + 1] == '|' && ++amnt)
			i += 2;
		if (!sqo && !dqo && (line[i] == '&' && line[i + 1] == '&') && ++amnt)
			i += 2;
		if (amnt == (cmd_no + 1))
			return (line + i);
		i++;
	}
	return (NULL);
}

static int	get_args_nu(char *line, int len)
{
	int		amnt;
	t_bool	sqo;
	t_bool	dqo;

	amnt = 0;
	sqo = FALSE;
	dqo = FALSE;
	while (*line && len--)
	{
		
	}
	return (amnt);
}

// static char	**get_args(t_prg_data *prg_data, char *line,
// 	int len, int cmd_no)
// {
// 	char	*end;
// 	t_bool	sqo;
// 	t_bool	dqo;

// 	sqo = FALSE;
// 	dqo = FALSE;
// 	while (*line)
// 	{
// 		line++;
// 	}
// 	return (NULL);
// }

static t_command	*create_commands(t_prg_data *prg_data, char *line,
	int len, int cmd_no)
{
	t_command	*cmds;
	char		*end;

	(void)len;
	(void)cmd_no;
	cmds = malloc(sizeof(t_command) * (1));
	cmds[0] = default_command();
	cmds[0].env = prg_data->env;
	while (*line == ' ' || *line == '\t')
		line++;
	end = line;
	while (*end != '\0' && *end != ' ' && *end != '\t' && *end != '|'
		&& !(*end == '&' && *(end + 1) == '&'))
		end++;
	cmds[0].cmd = ft_substr(line, 0, end - line);
	// cmds[0].args = malloc(sizeof(char *) * (get_args_nu(line, len) + 1));
	printf("cmd: \"%s\" | strlen: %ld\n", cmds[0].cmd, ft_strlen(cmds[0].cmd));
	printf("args nu: %d\n", get_args_nu(end, len - ft_strlen(cmds[0].cmd)));
	return (NULL);
}

// returns an array of commands
t_command	*get_commands(t_prg_data *prg_data, char *line, int cmd_no)
{
	long int	max;
	void		*tmp;

	(void)prg_data;
	line = (char *)get_to_command(line, cmd_no);
	printf("[DEBUG] | cmd [%d]: %s\n", cmd_no, line); // TODO: remove DEBUG print
	if (!line) // TODO: check if this is needed or add safety check
		return (NULL);
	tmp = get_to_command(line, cmd_no + 1);
	if (tmp)
		max = ((char *)tmp - 2) - line;
	else
		max = ft_strlen(line);
	printf("[TEST] | %s | %s\n", line, (char *)get_to_command(line, cmd_no + 1)); // TODO: remove DEBUG print
	printf("[TEST] | LEN=%ld\n", max); // TODO: remove DEBUG print
	return (create_commands(prg_data, line, max, cmd_no));
}
