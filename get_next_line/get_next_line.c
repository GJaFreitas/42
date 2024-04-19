/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:11:56 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 19:44:51 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	text[BUFFER_SIZE];
	char	*ret_ptr;
	int	err;
	int	size;

	err = read(fd, text, BUFFER_SIZE);
	if (err == -1)
		return (NULL);
	if (!err)
		return (NULL) ;
	size = ft_get_buff_size(text);
	ret_ptr = malloc(size + 1);
	ret_ptr[size] = 0;
	ft_memcpy(ret_ptr, text, size);
	return (ret_ptr);
}
