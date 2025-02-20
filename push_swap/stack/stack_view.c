#include "../includes/push_swap.h"

void	stack_print(const t_stack s)
{
	int	i;

	i = 0;
	if (s.size == 0)
		return (printf("Empty.\n"), (void)0);
	ft_printf("[ ");
	while (i < s.size)
	{
		ft_printf("%d", s.a[i]);
		i++;
		if (i < s.size)
			ft_printf(", ");
	}
	ft_printf(" ]");
	ft_printf("\n");
}

