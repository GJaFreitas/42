/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:25:10 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 18:56:23 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_write_printf(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	free(s);
	return (count);
}

static int	data(char c, va_list args)
{
	int	count;

	count = 1;
	if (c == 'i' || c == 'd')
		count = ft_write_printf(ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		count = ft_write_printf(ft_uitoa(va_arg(args, int)));
	else if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		count = ft_write_printf(ft_itox(va_arg(args, int)));
	else if (c == 'X')
		count = ft_write_printf(ft_itox_up(va_arg(args, int)));
	else if (c == 'p')
		count = ft_write_printf(ft_itoptr(va_arg(args, size_t)));
	else
		count = 0;
	return (count);
}
// Max int protection for itox and itoX

int	ft_printf(const char *input, ...)
{
	va_list	arg_list;
	int		count;

	if (!input)
		return (-1);
	va_start(arg_list, input);
	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input != '%')
			{
				count--;
				count += data(*(char *)input, arg_list);
			}
			else
				ft_putchar(*input);
		}
		else
			ft_putchar(*input);
		count++;
		input++;
	}
	va_end(arg_list);
	return (count);
}
