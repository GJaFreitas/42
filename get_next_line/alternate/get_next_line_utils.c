/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:14:05 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/14 20:37:02 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

			#include <stdio.h>
#include "get_next_line.h"

int	ft_str_lncp(int flag, char *buffer, char *dest, int n)
{
	int	len;
	
	len = 0;
	if (flag == 0)
	{
		if (!buffer)
			return (0);
		while (buffer[len])
			len++;
	}
	else
	{
		while (len < n)
		{
			dest[len] = buffer[len];
			len++;
		}
		if (len)
		{
			dest[len] = 0;
			printf("%p\n", &dest[len]);
		}
	}
	return (len);
}

void	ft_parse(char *buffer, char *leftovers)
{
	int	size;
	int	i;

	i = 0;
	if (*buffer == '\n')
		buffer++;
	size = ft_str_lncp(0, buffer, NULL, 0);
	while (*buffer)
	{
		leftovers[i++] = *buffer;
		buffer++;
	}
	leftovers[size] = 0;
}

char	*ft_strjoin(char *str, char *buffer, char *leftovers)
{
	char	*return_str;
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_str_lncp(0, str, NULL, 0);
	while (leftovers != NULL && leftovers[i])
		i++;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	return_str = malloc(len + j + 2);
	printf("max adress:%p\n", return_str + len + j + 2);
	ft_str_lncp(1, leftovers, return_str, i);
	ft_str_lncp(1, str, &return_str[i], len);
	ft_str_lncp(1, buffer, &return_str[len + i], j);
	ft_parse(&buffer[j], leftovers);
	free(str);
	return (return_str);
}

char	*ft_cleanup(char *str)
{
	free(str);
	return (NULL);
}
