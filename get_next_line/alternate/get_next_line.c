/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:09:58 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/14 19:39:48 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*output;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes_read = BUFFER_SIZE + 1;
	output = malloc(1);
	output[0] = 0;
	*buffer = 0;
	while (bytes_read >= BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		if (bytes_read == -1
			|| (bytes_read == 0 && !(*leftover) && !(*output)))
			return (ft_cleanup(output));
		output = ft_strjoin(output, buffer, leftover);
		if (output[ft_str_lncp(0, output, NULL, 0) - 1] == '\n')
			break ;
	}
	return (output);
}
