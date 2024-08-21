/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:45:20 by gjacome-          #+#    #+#             */
/*   Updated: 2024/06/21 00:28:27 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "libft/ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int	*arr;
	int	top;
} Stack;

void	push_swap(char *input);
void    ft_swap_top(Stack *stack);
void    ft_double_swap(Stack *a, Stack *b);
void    ft_push(Stack *origin, Stack *dest);
void    ft_reverse_rotate(Stack *stack);
void    ft_rotate(Stack *stack);
void    ft_logic(Stack *a, Stack *b);

#endif
