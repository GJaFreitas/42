/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:15:09 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/21 16:13:33 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "get_next_line.h"

int	found_endline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_listinit(t_list *list)
{
	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (1);
	list->next = NULL;
	list->str = NULL;
	return (0);
}

int	ft_addnode(t_list *list, char *buff, int size)
{
	int	i;

	i = 0;
	while (list->next != NULL)
		list = list->next;
	list->next = malloc(sizeof(t_list));
	if (ft_listinit(list->next))
		return (1);
	list = list->next;
	list->str = malloc(size + 1);
	if (list->str == NULL)
		return (1);
	while (i < size)
	{
		list->str[i] = buff[i];
		i++;
	}
	list->str[size] = 0;
	return (0);
}

int	ft_readfile(t_list *list, int fd)
{
	char	buff[256];
	int	count;

	if (read(fd, NULL, 0) == -1)
		return (2);
	ft_listinit(list);
	while ((count = read(fd, buff, BUFFER_SIZE)) != 0)
	{
		buff[count] = 0;
		if (ft_addnode(list, buff, count))
			return (1);
		if (found_endline(buff))
			break ;
	}
	return (0);
}

char	*ft_getstring(t_list *list);

