/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:42:31 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/08 15:50:35 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int	strlen;

	strlen = ft_strlen((char *)s);
	new_str = malloc(strlen + 1);
	ft_strlcpy(new_str, s, strlen + 1);
	return (new_str);
}
