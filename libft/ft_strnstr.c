/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:18:01 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/10 17:41:06 by gjacome-         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include <stddef.h>

static int	compare(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s2 == 0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (needle[0] == 0)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if ((*haystack == *needle) && compare(haystack, needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
