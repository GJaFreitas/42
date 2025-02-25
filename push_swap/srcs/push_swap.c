#include "../includes/push_swap.h"

static t_stack	*__init_stack(int argc, char **argv)
{
	t_stack	*temp;
	t_stack	*ret;
	char	**nums;
	int	i;
	int	flag;

	temp = stack_new();
	flag = 0;
	if (argc < 2)
	{
		nums = ft_split(argv[1], ' ');
		flag = 1;
	}
	else
		nums = &argv[1];
	i = 0;
	while (nums[i])
	{
		stack_add(temp, ft_atoi(nums[i]));
		i++;
	}
	if (flag)
		free(nums);
	ret = map_stack(temp);
	free(temp);
	return (ret);
}

// Initializes the stacks and other data. The stacks are initialized in the
// mapped form
static int	__init_data(t_ps *data, int argc, char **argv)
{
	ft_memset(data, 0, sizeof(t_ps));
	data->b = stack_new();
	if (!data->b)
		return (1);
	data->a = __init_stack(argc, argv);
	if (!data->a)
		return (1);
	return (0);
}

static void	__terminate_data(t_ps *data)
{
	free(data->a);
	free(data->b);
	ft_lstclear(&data->op_list, free);
}

// TODO: Function to check argv for duplicates or more than 500 entries
int	main(int argc, char **argv)
{
	t_ps	data;

	if (__init_data(&data, argc - 1, argv))
		return (1);
	/*
	stack_print(data.a);
	if (stack_issorted(data.a))
		;
	else if (data.a->size == 3)
		ft_sort_three(&data);
	else
		chunk_sort(&data);
	*/
	//print_op(data.op_list);
	stack_print(data.a);
	test(&data);
	__terminate_data(&data);
	return (0);
}
