/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:59:10 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/19 18:18:39 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	simple_sort(t_ps *data)
{
	int	size;

	if (is_sorted(data->stack_a) || ft_lstsize(*(data->stack_a)) == 0
		|| ft_lstsize(*data->stack_a) == 1)
		return ;
	size = ft_lstsize(*data->stack_a);
	if (size == 2)
		sa(data);
	else if (size == 3)
		sort_3(data);
	else if (size == 4)
		sort_4(data);
	else if (size == 5)
		sort_5(data);
}

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(t_ps *data)
{
	if (ft_lstsize(*(data->stack_a)) <= 5)
		simple_sort(data);
	else
		radix_sort(data);
}

static void	__init(t_ps *data, int argc, char **argv)
{
	data->stack_a = ft_calloc(1, sizeof(t_list));
	data->stack_b = ft_calloc(1, sizeof(t_list));
	data->op_list = NULL;
	init_stack(data->stack_a, argc, argv);
}

int	main(int argc, char **argv)
{
	t_ps	data;

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);
	__init(&data, argc, argv);
	if (is_sorted(data.stack_a))
	{
		free_stack(data.stack_a);
		free_stack(data.stack_b);
		return (0);
	}
	sort_stack(&data);
	post_sort_opt(&data);
	print_ops(&data);
	free_stack(data.stack_a);
	free_stack(data.stack_b);
	free_doubly(data.op_list);
	return (0);
}
