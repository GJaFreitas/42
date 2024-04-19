/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:15:09 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 10:59:50 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "get_next_line.h"

void	*ft_realloc(void *origin, unsigned int originsize)
{
	unsigned int	i;
	void	*new_ptr;

	new_ptr = malloc(originsize * 2);
	i = 0;
	while (i < originsize)
		((unsigned char *)new_ptr)[i] = ((unsigned char *)origin)[i];
	free(origin);
	return (new_ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ret_ptr;

	ret_ptr = dest;
	while (n > 0)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		n--;
	}
	return (ret_ptr);
}
