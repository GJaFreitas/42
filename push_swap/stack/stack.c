/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:52 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:52 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
	In some of the code i take into account that i need to do
	stack->size - 1, in other parts my brain was apparently turned off
*/

void	stack_add(t_stack *stack, int num)
{
	if (stack->size < STACK_SIZE)
		stack->a[stack->size++] = num;
}

int	stack_pop(t_stack *stack)
{
	int	pop;

	if (stack->size > 0)
	{
		stack->size--;
		pop = stack->a[stack->size];
		return (pop);
	}
	return (0);
}

// Takes a peek from the top of the stack
// Beware dear user, n does not start from 0. The top of the stack is 1
int	stack_peek(const t_stack *stack, int n)
{
	int	i;

	i = stack->size - n + 1 - 1;
	return (stack->a[i]);
}

void	stack_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	temp = stack->a[0];
	stack->size--;
	i = 0;
	while (i < stack->size)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack_add(stack, temp);
}

void	stack_rev_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	temp = stack_pop(stack);
	i = stack->size - 1;
	while (i >= 0)
	{
		stack->a[i + 1] = stack->a[i];
		i--;
	}
	stack->a[0] = temp;
	stack->size++;
}
