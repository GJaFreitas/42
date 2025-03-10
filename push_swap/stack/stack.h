/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:56 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:56 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define STACK_SIZE 500

# include "../libft/libft.h"

/*
	I seriously should have a stack->top but at this point
	im in too deep
	size - 1 will have to do..... oh how i wish i could
	have a method that returns size - 1... stack->top() :(
*/

typedef struct s_stack
{
	int	a[STACK_SIZE];
	int	size;
}	t_stack;

t_stack	*stack_new(void);
t_stack	*stack_copy(const t_stack *stack);
void	stack_add(t_stack *stack, int num);
int		stack_pop(t_stack *stack);
int		stack_peek(const t_stack *stack, int n);
void	stack_rotate(t_stack *stack);
void	stack_rev_rotate(t_stack *stack);
int		stack_min(const t_stack *stack);
int		stack_max(const t_stack *stack);
int		stack_issorted(const t_stack *stack);
int		stack_empty(const t_stack *stack);
int		stack_find(const t_stack *stack, int n);
void	stack_print(const t_stack *s);

#endif
