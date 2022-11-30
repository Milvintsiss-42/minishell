/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:01:00 by oaarsse           #+#    #+#             */
/*   Updated: 2022/11/30 13:02:00 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	print_heredoc_prio(t_prg_data *data, t_command *command,
	int is_infile)
{
	if (is_infile == 1)
	{
		if (command->here_doc_limiter && command->infile)
			ft_printf_fd(2, "%s: %s%s%s\n", (*data).bin_name,
				"Heredoc have priority over infile redirection. ",
				command->infile, " will be ignored");
	}
	if (is_infile == 2)
		if (command->infile)
			ft_printf_fd(2, "%s: %s%s%s\n", (*data).bin_name,
				"Heredoc have priority over infile redirection. ",
				command->infile, " will be ignored");
	return (1);
}

static void	multiple_out_in(t_prg_data *data, t_command *command,
	int is_infile)
{
	if (is_infile == 1)
	{
		if (command->infile)
			ft_printf_fd(2, "%s: %s%s%s\n", (*data).bin_name,
				"Multiple infile redirection, ", command->infile,
				" will be ignored. Only the last will be considered");
	}
	else if (is_infile == 0)
	{
		if (command->outfile)
			ft_printf_fd(2, "%s: %s%s%s\n", (*data).bin_name,
				"Multiple outfile redirection, ", command->outfile,
				" will be ignored. Only the last will be considered");
	}
	else if (is_infile == 2)
	{
		if (command->here_doc_limiter)
			ft_printf_fd(2, "%s: %s%s%s\n", (*data).bin_name,
				"Multiple heredoc limiter, ", command->here_doc_limiter,
				" will be ignored. Only the last will be considered");
	}
}

static int	handle_rd_stdin_heredoc(t_prg_data *data, t_token_separator sep,
		t_command *command, t_lst_tokens **tokens)
{
	if (sep == e_RD_STDIN_HEREDOC)
	{
		multiple_out_in(data, command, 2);
		print_heredoc_prio(data, command, 2);
		free(command->infile);
		command->infile = NULL;
		if (command->here_doc_limiter)
			free(command->here_doc_limiter);
		command->here_doc_limiter = ft_strdup((*tokens)->next->token);
		if (!command->here_doc_limiter)
			return (-1);
	}
	else if (sep == e_RD_STDIN)
	{
		multiple_out_in(data, command, 1);
		if (command->infile)
			free(command->infile);
		command->infile = ft_strdup((*tokens)->next->token);
		if (!command->infile)
			return (-1);
		if (command->here_doc_limiter && print_heredoc_prio(data, command, 1))
			return (1);
	}
	return (1);
}

int	handle_files(t_prg_data *data, t_token_separator sep,
	t_command *command, t_lst_tokens **tokens)
{
	if (sep != e_RD_FILE && sep != e_RD_FILE_APN && sep != e_RD_STDIN
		&& sep != e_RD_STDIN_HEREDOC)
		return (0);
	if (sep == e_RD_FILE || sep == e_RD_FILE_APN)
	{
		multiple_out_in(data, command, 0);
		if (sep == e_RD_FILE_APN)
			command->is_append_mode = TRUE;
		if (command->outfile)
			free(command->outfile);
		command->outfile = ft_strdup((*tokens)->next->token);
		if (!command->outfile)
			return (-1);
	}
	else if (handle_rd_stdin_heredoc(data, sep, command, tokens) == -1)
		return (-1);
	*tokens = (*tokens)->next;
	return (1);
}
