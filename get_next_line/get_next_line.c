/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:11:56 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/21 17:10:13 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// Reads input from fd until a \n character or an EOF
char	*get_next_line(int fd)
{
	char	*ret;
	static t_list	**list;

	list = malloc(sizeof(size_t *));
	*list = NULL;
	if (ft_readfile(list, fd))
		return (NULL);
	ret = ft_getstring(list);
	return (ret);
}
