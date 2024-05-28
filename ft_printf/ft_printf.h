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
# include "libft/libft.h"

int	    ft_printf(char *input, ...);
int     ft_printdata(int *count, char specifier, va_list arg_list);
void    ft_printptr(int *count, unsigned long int num);
void    ft_printhexbig(int *count, unsigned long int num);
void    ft_printhexsmall(int *count, unsigned long int num);
void    ft_printint(int *count, int num);
void    ft_printuint(int *count, unsigned long int num);
void    ft_printstring(int *count, char *str);
void    ft_printchar(int *count, char c);

#endif
