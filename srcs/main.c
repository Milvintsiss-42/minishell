/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 01:58:09 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/28 21:27:25 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "cli.h"
#include <stdlib.h>

int	g_last_exit_status = 0;

static void	exit_init(t_prg_data *prg_data, int err)
{
	clear_prg_data(prg_data);
	exit(err);
}

static void	init_prg_data(t_prg_data *prg_data, int argc, char const **argv,
	char *const *env)
{
	int	err;

	if (argc < 1 || !argv[0])
		exit(1);
	prg_data->commands = 0;
	prg_data->nb_commands = 0;
	prg_data->cur_pipeline = 0;
	prg_data->nb_cmds_in_pl = 0;
	prg_data->history = 0;
	prg_data->len_history = 0;
	prg_data->env = 0;
	prg_data->bin_name = ft_basename(argv[0]);
	if (!prg_data->bin_name)
		exit_init(prg_data, errno);
	err = copy_env_to_heap(prg_data, &prg_data->env, env);
	if (err != 0)
		exit_init(prg_data, err);
	if (get_env_element_address_by_name(prg_data, "PWD") == 0)
		err = updates_env_pwd(prg_data);
	if (err != 0)
		exit_init(prg_data, err);
	err = update_shell_lvl(prg_data);
	if (err != 0)
		exit_init(prg_data, err);
}

int	main(int argc, char const **argv, char *const *env)
{
	t_prg_data	prg_data;

	init_prg_data(&prg_data, argc, argv, env);
	if (KDEBUG_EXEC)
		return (test_execution(&prg_data));
	ft_print_logo();
	ft_loop_input(&prg_data);
	return (0);
}
