/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:40:53 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/09 15:46:54 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_while_condition(int *bytes_read, int fd, char *buff)
{
	*bytes_read = read(fd, buff, BUFFER_SIZE);
	return (*bytes_read);
}

char	*read_line(t_data *data, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*ret;
	int		bytes_read;
	int		count;

	count = 0;
	ret = NULL;
	buff[0] = 0;
	while (ft_while_condition(&bytes_read, fd, buff) != 0)
	{
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = 0;
		data->size += bytes_read;
		ft_strjoin(data, buff);
		while (data->leftover[count] && data->leftover[count++] != '\n')
			;
		if (data->leftover[count - 1] == '\n')
			break ;
	}
	if (data->leftover[0] != 0)
		ret = ft_getline(data, count);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_data	*data;
	t_data			*temp;
	char			*ret;
	int				i;

	i = 0;
	if (data == NULL)
	{
		data = malloc(sizeof(t_data));
		data->leftover = malloc(1);
		*(data->leftover) = 0;
		data->size = 1;
	}
	temp = data;
	while (temp->leftover[i] && temp->leftover[i] != '\n')
		i++;
	if (temp->leftover[i] == '\n')
		ret = ft_getline(temp, i + 1);
	else
		ret = read_line(temp, fd);
	return (ret);
}
