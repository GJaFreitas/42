/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:27:37 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/20 18:42:42 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*__init_stack(int argc, char **argv, int flag)
{
	t_stack	*temp;
	t_stack	*ret;
	char	**nums;
	int		i;

	temp = stack_new();
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
	if (argc > 500)
		return (1);
	if (ft_check_args(argc, argv))
		return (1);
	ft_memset(data, 0, sizeof(t_ps));
	data->b = stack_new();
	if (!data->b)
		return (1);
	data->a = __init_stack(argc, argv, 0);
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

	if (argc == 1)
		return (0);
	if (__init_data(&data, argc - 1, argv))
		return (__terminate_data(&data), err());
	if (stack_issorted(data.a))
		;
	else if (data.a->size <= 5)
		ft_sort_small(&data);
	else
		chunk_sort(&data);
	post_sort_opt(&data);
	print_op(data.op_list);
	__terminate_data(&data);
	return (0);
}
