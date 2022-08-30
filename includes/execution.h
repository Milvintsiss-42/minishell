/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:03:52 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/30 02:36:49 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

// ERR_CSM errors are custom errors that need arguments and to be printed with
// ft_print_fd.
// Others errors can be printed with perror.
# define ERR_CMD_NOT_FOUND		"Command not found"
# define ERR_CSM_EOF_IN_HERE_DOC	"%s: warning: here-document at line %d\
 delimited by end-of-file (wanted `%s')\n"

#endif