#ifndef STACK_H
# define STACK_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int	a[500];
	int	size;
}	t_stack;

t_stack	*stack_new();
t_stack	*stack_copy(const t_stack *stack);
void	stack_add(t_stack *stack, int num);
int	stack_pop(t_stack *stack);
int	stack_peek(const t_stack *stack, int n);
void	stack_rotate(t_stack *stack);
void	stack_rev_rotate(t_stack *stack);
int	stack_min(const t_stack *stack);
int	stack_max(const t_stack *stack);
int	stack_issorted(const t_stack *stack);
int	stack_empty(const t_stack *stack);
int	stack_find(const t_stack *stack, int n);
void	stack_print(const t_stack s);

#endif
