/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:59 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:59 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

int	stack_min(const t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size <= 0)
		return (INT_MAX);
	temp = INT_MAX;
	i = 0;
	while (i < stack->size)
	{
		if (stack->a[i] < temp)
			temp = stack->a[i];
		i++;
	}
	return (temp);
}

int	stack_max(const t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size <= 0)
		return (INT_MIN);
	temp = INT_MIN;
	i = 0;
	while (i < stack->size)
	{
		if (stack->a[i] > temp)
			temp = stack->a[i];
		i++;
	}
	return (temp);
}

// Returns 1 if the stack is sorted either in ascending order or descending
int	stack_issorted(const t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (!(stack->a[i] < stack->a[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	stack_empty(const t_stack *stack)
{
	return (stack->size == 0);
}

int	stack_find(const t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < STACK_SIZE)
	{
		if (stack->a[i] == n)
			return (i);
		i++;
	}
	return (501);
}
