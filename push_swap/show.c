#include "push_swap.h"

static void	__print_stack(const t_stack s)
{
	int	i;

	i = 0;
	if (s.size == 0)
		printf("Empty.\n");
	while (i < s.size)
	{
		ft_printf("%d", s.a[i]);
		i++;
		if (i < s.size)
			ft_printf(", ");
	}
	ft_printf("\n");
}

void	ft_show_stack(const t_stack a, const t_stack b)
{
	ft_printf("Stack A:\n");
	__print_stack(a);
	ft_printf("Stack B:\n");
	__print_stack(b);
}
