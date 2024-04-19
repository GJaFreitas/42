/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:15:09 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 19:38:58 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int	ft_get_buff_size(char *s)
{
	int	i;

	i = 0;
	while (s[i - 1] != '\n' && s[i])
		i++;
	printf("%d\n", i);
	return (i);
}
