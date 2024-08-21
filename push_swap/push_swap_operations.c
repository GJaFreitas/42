/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 00:33:17 by gjacome-          #+#    #+#             */
/*   Updated: 2024/06/21 00:33:29 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sucess 1 - 
void    ft_swap_top(Stack *stack)
{
    int temp;

    temp = stack->arr[stack->top - 1];
    stack->arr[stack->top - 1] = stack->arr[stack->top - 2];
    stack->arr[stack->top - 2] = temp;
}

void    ft_double_swap(Stack *a, Stack *b)
{
    ft_swap_top(a);
    ft_swap_top(b);
}

void    ft_push(Stack *origin, Stack *dest)
{
    dest->arr[dest->top + 1] = origin->arr[origin->top];
    dest->top++;
    origin->top--;
}

void    ft_reverse_rotate(Stack *stack)
{
    int temp;
    int i;

    i = 0;
    temp = stack->arr[stack->top];
    while (i < stack->top - 1)
    {
        stack->arr[i + 1] = stack->arr[i];
        i++;
    }
    stack->arr[0] = temp;
}

void    ft_rotate(Stack *stack)
{
    int temp;
    int i;

    i = stack->top;
    temp = stack->arr[0];
    while (i > 1)
    {
        stack->arr[i - 1] = stack->arr[i];
        i--;
    }
    stack->arr[stack->top] = temp;
}
