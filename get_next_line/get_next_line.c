/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:09:58 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/16 19:36:07 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*return_str;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return_str = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		return_str = ft_strjoin(return_str, buffer);
		if (return_str == NULL)
			return (NULL);
		if (return_str[ft_strlen(return_str, 1)] == '\n')
			return (return_str);
	}
	return (return_str);
}
