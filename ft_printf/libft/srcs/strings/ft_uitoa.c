/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:58:00 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/18 18:59:33 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*str;

	str = malloc(1);
	str[0] = 0;
	if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
