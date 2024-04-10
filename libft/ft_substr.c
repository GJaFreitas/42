/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:30:50 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/08 18:51:16 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	size;
	char	*sub_str;

	size = len - start;
	sub_str = malloc(size);
	if (sub_str == NULL)
		return (NULL);
	sub_str = (char *)s + start;
	return (sub_str);
}
