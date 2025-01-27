#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	a[500];
	int	size;
}	t_stack;

void	stack_add(t_stack *stack, int num);
int	stack_pop(t_stack *stack);
int	stack_peek(const t_stack *stack, int n);
void	stack_rotate(t_stack *stack);
void	stack_rev_rotate(t_stack *stack);
int	stack_min(const t_stack *stack);
int	stack_max(const t_stack *stack);
int	stack_issorted(const t_stack *stack);
int	stack_empty(const t_stack *stack);

#endif
