/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:30:50 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/10 15:12:37 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	size;
	char	*sub_str;

	size = len - start;
	sub_str = malloc(size);
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, s, size + 1);
	return (sub_str);
}
