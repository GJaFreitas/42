/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:40:43 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

// Frees a mem address and sets it to NULL to avoid double frees
int	free_safe(void **v)
{
	if (v && *v != NULL)
	{
		free(*v);
		*v = NULL;
		return (1);
	}
	return (0);
}

// Checks both if size is > 0 and the malloc return
// if malloc gives NULL then fuck it everything is destroyed
// and chaos is brought upon everyone and everything without
// impunity, no one is safe, all memory shall be freed
// and the program shall exit in a fiery fashion
void	*malloc_safe(size_t __size)
{
	void	*v;

	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		harbinger_of_chaos();
	ft_bzero(v, __size);
	return (v);
}
