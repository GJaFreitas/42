/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:59:38 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/17 17:51:37 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ret_ptr;

	ret_ptr = NULL;
	while (*s && *s != c)
		s++;
	if (*s == c)
		ret_ptr = (char *)s;
	if (c == 0)
		return ((char *)s);
	return (ret_ptr);
}
