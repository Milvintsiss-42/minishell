/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_defs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:50:55 by ple-stra          #+#    #+#             */
/*   Updated: 2022/08/30 02:48:12 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DEFS_H
# define LIBFT_DEFS_H

# define INTMIN 	-2147483648
# define INTMAX 	2147483647

# define TRUE		1
# define FALSE		0

# define HEX_BASE		"0123456789abcdef"
# define HEX_BASE_CAPS	"0123456789ABCDEF"
# define DEC_BASE		"0123456789"
# define OCT_BASE		"01234567"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif