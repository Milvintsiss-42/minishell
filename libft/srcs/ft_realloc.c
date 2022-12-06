/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:29:56 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/13 03:38:20 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t cur_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		free(ptr);
		return (0);
	}
	if (new_size < cur_size)
		cur_size = new_size;
	new_ptr = ft_memcpy(new_ptr, ptr, cur_size);
	free(ptr);
	return (new_ptr);
}
