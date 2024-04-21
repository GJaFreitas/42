/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:15:09 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/21 17:54:34 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "get_next_line.h"

// Auxiliary function used to detect a \n char
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

// Creates a node with default values
int	ft_listinit(t_list **list)
{
	if (*list == NULL)
		*list = malloc(sizeof(t_list));
	if (*list == NULL)
		return (1);
	(*list)->next = NULL;
	(*list)->str = NULL;
	return (0);
}

// Auxiliary function to ft_readfile(), adds a new node and copies over the buffer into it
int	ft_addnode(t_list **list, char *buff, int size)
{
	int	i;

	i = 0;
	while ((*list)->next != NULL)
		(*list) = (*list)->next;
	(*list)->next = malloc(sizeof(t_list));
	if (ft_listinit(&((*list)->next)))
		return (1);
	(*list) = (*list)->next;
	(*list)->str = malloc(size + 1);
	if ((*list)->str == NULL)
		return (1);
	while (i < size)
	{
		(*list)->str[i] = buff[i];
		i++;
	}
	(*list)->str[size] = 0;
	return (0);
}

// Read the contents of the file pointed to by fd until it reaches either the end of
// the file or a \n character into a linked list
int	ft_readfile(t_list **list, int fd)
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

// Malloc enough space for the string, copy it and then return it
char	*ft_returnstring(t_list **list, int len)
{
	char	*ret;
	t_list	*temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	temp = *list;
	ret = malloc(len + 2);
	if (ret == NULL)
		return (NULL);
	while (temp)
	{
		i = 0;
		while (temp->str[i] && temp->str[i - 1] != '\n')
			ret[j++] = temp->str[i++];
		if (temp->next != NULL)
			temp = temp->next;
		else
			break ;
	}
	ret[len + 1] = 0;
	return (ret);
}

// Trim the string by removing everything up until the \n
// and then copying it over to another str
void	ft_trimstring(t_list **lastnode)
{
	int	i;
	int	j;
	int	size;
	char	*trimmed_str;

	i = 0;
	j = 0;
	while ((*lastnode)->str[i] != '\n')
		i++;
	size = i;
	while ((*lastnode)->str[size])
		size++;
	trimmed_str = malloc(size + 1);
	while (i < size)
	{
		trimmed_str[j] = (*lastnode)->str[i];
		j++;
		i++;
	}
	trimmed_str[size] = 0;
	free((*lastnode)->str);
	(*lastnode)->str = trimmed_str;
}

// Free everything until the lastnode and changing the head of the list to the lastnode
void	ft_destroylist(t_list **list, t_list *lastnode)
{
	t_list	*temp;

	temp = *list;
	while (temp != lastnode)
	{
		*list = temp;
		temp = (*list)->next;
		free((*list)->str);
		free(*list);
	}
	ft_trimstring(&lastnode);
	*list = lastnode;
}

// Get the size of the string, copy it into a char* and then reset the list with
// the last node being the new head so that any left over text can be used later
char	*ft_getstring(t_list **list)
{
	t_list	*temp;
	char	*ret;
	int	i;
	int	len;

	i = 0;
	len = 0;
	temp = *list;
	while (temp)
	{
		while (temp->str[i] != '\n' && temp->str[i])
		{
			len++;
			i++;
		}
		if (temp->next != NULL)
			temp = temp->next;
		else
			break ;
	}
	ret = ft_returnstring(list, len);
	ft_destroylist(list, temp);
	return (ret);
}
