/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:18:30 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/22 18:16:06 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char		*return_string;

	if (list == NULL)
	{
		list = malloc(sizeof(t_list));
		list->next = NULL;
		list->str = NULL;
	}
	ft_read(list, fd);
	return_string = ft_getstring(&list);
	return (return_string);
}
