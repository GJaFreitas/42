/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:19:28 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/26 15:49:10 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_foundnl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_copybuf(t_list *list, char *buf, int size, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (flag)
	{
		if (list->str == NULL)
			list->str = malloc(size + 1);
		else
			while (list->str[j])
				j++;
		while (buf[i])
			list->str[j++] = buf[i++];
		list->str[j] = 0;
	}
	else
	{
		while (list->str[size])
			list->str[i++] = list->str[size++];
		list->str[i] = 0;
	}
}

void	ft_read(t_list *list, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int	size;

	if ((read(fd, NULL, 0)) == -1)
		return ;
	while ((size = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		buf[size] = 0;
		ft_copybuf(list, buf, size, 1);
		if (ft_foundnl(buf))
			break ;
		list->next = malloc(sizeof(t_list));
		list = list->next;
		list->next = NULL;
	}
}

int	ft_copyandfree(char *ret, t_list **list)
{
	t_list	*temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*list)->str[i] != '\n')
	{
		if ((*list)->str[i] == 0)
		{
			temp = (*list);
			(*list) = (*list)->next;
			free(temp->str);
			free(temp);
			i = 0;
		}
		ret[j++] = (*list)->str[i++];
	}
	ret[j] = '\n';
	ret[j + 1] = 0;
	return (i);
}

char	*ft_getstring(t_list **list)
{
	char	*ret;
	int	size;
	int	i;

	i = 0;
	size = 0;
	while ((*list)->str[i - 1] != '\n' && (*list)->str[i])
	{
		if ((*list)->str[i++] == 0)
		{
			(*list) = (*list)->next;
			i = 0;
		}
		size++;
	}
	if (size == 0)
		return (NULL);
	ret = malloc(size + 2);
	i = ft_copyandfree(ret, list);
	ft_copybuf(*list, NULL, i + 1, 0);
	return (ret);
}
