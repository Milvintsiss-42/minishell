/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 01:58:09 by ple-stra          #+#    #+#             */
/*   Updated: 2022/10/10 20:57:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static void	init_prg_data(t_prg_data *prg_data, int argc, char const **argv,
	char *const *env)
{
	if (argc < 1 || !argv[0])
		exit(1);
	prg_data->bin_name = argv[0];
	prg_data->env = env;
}

int	main(int argc, char const **argv, char *const *env)
{
	t_prg_data	prg_data;

	init_prg_data(&prg_data, argc, argv, env);
	if (KDEBUG_EXEC)
		test_execution(&prg_data);
	// ask indefinitely for a command
		// each command input is parsed
		// listen for signals CTRL + D or C or /
	return (0);
}
