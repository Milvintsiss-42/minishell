/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:22:18 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/20 02:40:56 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "parsing.h"
#include "cli.h"
#include "signals.h"

static void	handle_parsing_exec(t_prg_data *data, char	*line)
{
	t_command	*cmds;
	int			cmd_no;

	cmd_no = 0;
	cmds = parsing(data, line);
	if (!cmds)
		return ;
	//TODO: execution
	execute(data);
	cmd_no++;
}

static char	*get_prompt(t_prg_data *data)
{
	char	*prompt;
	char	*pwd;
	char	*pwd_basename;

	pwd = get_env_element_value_by_name(data, "PWD");
	if (!pwd)
		return (0);
	pwd_basename = ft_basename(pwd);
	free(pwd);
	if (!pwd_basename)
		return (0);
	ft_vasprintf(&prompt, "-> %s$ ", pwd_basename);
	free(pwd_basename);
	return (prompt);
}

// ask indefinitely for a command
// each command input is parsed and executed
//TODO: listen for signals CTRL + D or C or /
void	ft_loop_input(t_prg_data *data)
{
	char		*line;
	char		*prompt;

	ft_signal_handler();
	while (TRUE)
	{
		prompt = get_prompt(data);
		if (prompt)
			line = readline(prompt);
		else
			line = readline("$ ");
		free(prompt);
		if (!line)
		{
			// CTRL + D case
			printf("exit\n");
			exit(0); // TODO: handle exit + clean
		}
		if (ft_strlen(line) > 0)
			add_history(line); //TODO: free history at the end -> rl_clear_history();
		handle_parsing_exec(data, line);
		free(line); //TODO: free allocated stuffs
	}
}
