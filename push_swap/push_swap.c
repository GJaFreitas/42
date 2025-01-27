#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	static t_stack	a;
	static t_stack	b;
	t_stack	*ptra;
	t_stack	*ptrb;

	if (argc < 2)
		return (argc);
	else
		ft_parse(argv, argc, &a);
	ft_show_stack(a, b);

	ptra = malloc(sizeof(t_stack));
	ptrb = malloc(sizeof(t_stack));
	ft_algo(ft_memcpy(ptra, &a, sizeof(t_stack)),\
	 ft_memcpy(ptrb, &b, sizeof(t_stack)));

	printf("\n\n");

	optimize_instructions(exec_instruction(NULL));
	exec(&a, &b, exec_instruction(NULL));
	ft_show_stack(a, b);
	free(ptra);
	free(ptrb);
	return (0);
}
