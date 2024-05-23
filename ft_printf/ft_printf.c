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

int	ft_printf(const char *input, ...)
{
	va_list	arg_list;
    t_data  *data;
	int		count;
	int		i;

    data = ft_initialize();
    i = 0;
    while (input[i])
    {
        if (input[i] != '%')
        {
            write(1, &input[i], 1);
            data->count += 1;
        }
        else
        {
           i += ft_parse(data, input, arg_list);
           ft_printdata(data, arg_list, input[i]);
        }
        i++;
    }
    free(data);
	return (count);
}
