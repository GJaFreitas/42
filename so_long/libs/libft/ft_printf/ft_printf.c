/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:33:24 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 18:33:36 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_main_loop(char **input, va_list args)
{
	int	count;

	count = 0;
	if (**input == '%')
	{
		(*input)++;
		if (ft_strchr(POSSIBLE_FLAGS, **input))
			count = ft_nexus(**input, args);
		else if (**input == ' ')
			count = write(1, " ", 1);
		else
			count = write(1, "%", 1);
	}
	else
	{
		count = write(1, *input, 1);
	}
	(*input)++;
	return (count);
}

int	ft_printf(char *input, ...)
{
	int		count;
	va_list	args;

	va_start(args, input);
	count = 0;
	if (!input)
		return (-1);
	while (*input)
	{
		count += ft_main_loop(&input, args);
	}
	va_end(args);
	return (count);
}
