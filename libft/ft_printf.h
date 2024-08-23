/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:24:53 by gjacome-          #+#    #+#             */
/*   Updated: 2024/08/19 16:11:57 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define BASE_10 "0123456789"
# define POSSIBLE_FLAGS "cspdiuxX%"

int		ft_printf(char *input, ...);
int		ft_nexus(char input, va_list args);
int		ft_putnbr_base(unsigned int nbr, char *base, int total);
int		ft_printchar(char c);
int		ft_printstring(char *str);
int		ft_printint(int n);
int		ft_printuint(unsigned int n);
int		ft_printhexbig(unsigned int n);
int		ft_printhexsmall(unsigned int n);
int		ft_printptr(void *ptr);

#endif
