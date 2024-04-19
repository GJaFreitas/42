/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:11:56 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 11:27:11 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*text;
	char	*ret_ptr;
	int	size;
	int	count;

	size = 64;
	text = malloc(size);
	count = 0;
	while (text[count] != '\n')
	{
		if (!read(fd, &text[count], 1))
			break;
		if (count == size - 1)
		{
			text = ft_realloc(text, size);
			size *= 2;
		}
		count++;
	}
	ret_ptr = malloc(count + 1);
	ret_ptr[count] = 0;
	ft_memcpy(ret_ptr, text, count - 1);
	free(text);
	return (ret_ptr);
}
