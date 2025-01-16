#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (argc);
	if (argc < 3)
		ft_parse(argv, argc, &a);
	ft_algo(&a, &b);
	return (0);
}
