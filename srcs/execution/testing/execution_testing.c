/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:10:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/08 18:44:18 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// This execution is not protected as it is only used for debugging purposes
// cat << HERE > outfile | echo "hello world" | cat < infile | cat <<HERE2
// ls -la | cat -e
// cd "includes" | pwd | cat -e
// cd "srcs"
// pwd
// echo -n hello world
// exit
int	test_execution(t_prg_data *prg_data)
{
	test_execution_first_pipeline(prg_data);
	test_execution_second_pipeline(prg_data);
	test_execution_third_pipeline(prg_data);
	test_execution_fourth_pipeline(prg_data);
	test_execution_fifth_pipeline(prg_data);
	test_execution_sixth_pipeline(prg_data);
	test_execution_seventh_pipeline(prg_data);
	printf("Should never print as program exited previously\n");
	return (0);
}
