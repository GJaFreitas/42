/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:31:05 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/08 15:40:01 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

// nmemb = n members of size x
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	if (nmemb * size > INT_MAX)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	ptr = malloc(nmemb * size);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
