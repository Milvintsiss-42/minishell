/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaarsse <oaarsse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 01:58:09 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/06 18:45:46 by oaarsse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "cli.h"
#include <stdlib.h>

static void	init_prg_data(t_prg_data *prg_data, int argc, char const **argv,
	char const **env)
{
	if (argc < 1 || !argv[0])
		exit(1);
	prg_data->bin_name = argv[0];
	prg_data->env = env;
}

int	main(int argc, char const **argv, char const **env)
{
	t_prg_data	prg_data;

	init_prg_data(&prg_data, argc, argv, env);
	// if (KDEBUG_EXEC)
	// 	test_execution(&prg_data);
	ft_print_logo();
	ft_loop_input(&prg_data);
	return (0);
}
