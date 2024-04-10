/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:01:57 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/10 15:53:08 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char *return_ptr;

	return_ptr = NULL;
	while (s != 0)
	{
		if (*s == c)
			return_ptr = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (return_ptr);
}
