/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:14:05 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/20 19:16:33 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s, int flag)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	if (flag == 0)
	{
		while (s[len])
			len++;
	}
	else if (flag == 1)
	{
		while (s[len] && s[len] != '\n')
			len++;
	}
	return (len);
}

void	ft_parse(char *buffer, int written)
{
	int	i;

	i = 0;
	while (buffer[written])
		buffer[i++] = buffer[written++];
	while (i < BUFFER_SIZE)
		buffer[i++] = 0;
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*ret_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (buffer[0] == 0 && str && str[0] == 0)
		return (NULL);
	ret_str = malloc(ft_strlen(str, 0) + ft_strlen(buffer, 1) + 2);
	if (!ret_str)
	{
		free(str);
		return (NULL);
	}
	while (str && str[j])
		ret_str[i++] = str[j++];
	j = 0;
	while (buffer[j] && buffer[j - 1] != '\n')
		ret_str[i++] = buffer[j++];
	ret_str[i] = 0;
	free(str);
	ft_parse(buffer, j);
	return (ret_str);
}
