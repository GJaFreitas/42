/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:50:02 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/15 18:35:36 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (ft_substr(s1, 0, i));
}
