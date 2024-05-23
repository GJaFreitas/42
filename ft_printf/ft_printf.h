/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:24:53 by gjacome-          #+#    #+#             */
/*   Updated: 2024/04/19 15:26:30 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef short int bool;

typedef struct s_data
{
    char    specifiers[10] = "cspdiuxX%";

    bool flag_minus;
    bool flag_0;
    bool flag_alt;
    bool flag_space;
    bool flag_plus;

    int count;
    int precision;
    int width;
} t_data;

int	ft_printf(const char *input, ...);
int    ft_parse(t_data *data, const char *input, va_list arg_list);
t_data    *ft_initialize();
void    ft_printdata(t_data *data, va_list arg_list, char specifier);
void    ft_printint(t_data *data, int num);
void    ft_printuint(t_data *data, unsigned int num);
void    ft_printhexsmall(t_data *data, unsigned int num);
void    ft_printhexbig(t_data *data, unsigned int num);
void    ft_printchar(t_data *data, char c);
void    ft_printstring(t_data *data, char *str);
void    ft_printptr(t_data *data, void *ptr);

#endif
