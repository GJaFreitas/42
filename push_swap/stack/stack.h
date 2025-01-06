#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	a[500];
	int	size;
}	t_stack;

void	stack_add(t_stack *stack, int num);
void	stack_remove(t_stack *stack);

#endif
