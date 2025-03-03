#include "../includes/push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	if (!s)
		return (NULL);
	return (s);
}

t_stack	*stack_copy(const t_stack *stack)
{
	t_stack	*copy;

	copy = stack_new();
	ft_memcpy(copy, stack, sizeof(t_stack));
	return (copy);
}
