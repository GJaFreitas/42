/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:09:58 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/16 19:52:33 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*return_str;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	return_str = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE))
	{
		return_str = ft_strjoin(return_str, buffer[fd]);
		if (return_str == NULL)
			return (NULL);
		if (return_str[ft_strlen(return_str, 1)] == '\n')
			return (return_str);
	}
	return (return_str);
}
