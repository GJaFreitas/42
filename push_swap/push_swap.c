#include "push_swap.h"

void	create_list_split(t_dlist *a, char **argv)
{

}

void	create_list_it(t_dlist *a, char **argv)
{
}

int	main(int argc, char **argv)
{
	t_dlist	a;
	t_dlist	b;

	if (argc < 2)
		return (argc);
	if (argc < 3)
		create_list_split(&a, argv);
	else
		create_list_it(&a, argv);
	return (0);
}
