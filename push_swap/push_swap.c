/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:48:33 by gjacome-          #+#    #+#             */
/*   Updated: 2024/06/21 00:29:40 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_realloc(Stack *origin, int size, int *start_size)
{
	int	*ret;
	int	i;

    i = 0;
	ret = malloc((size * 2) * sizeof(int));
	while (i < size)
	{
		ret[i] = origin->arr[i];
		i++;
	}
    if (origin->arr != NULL)
        free(origin->arr);
    origin->arr = ret;
    *start_size = size * 2;
	return (ret);
}

Stack   *ft_stackalloc()
{
    Stack   *ret;

    ret = malloc(sizeof(Stack));
    ret->arr = malloc(sizeof(int));;
    ret->top = 0;
    return (ret);
}

// TODO: make it so this function can parse double digit numbers
static int  ft_parseinput(char *input, Stack *ret)
{
	int	    i;
	int	    size;

	i = 0;
    size = 1;
	while (*input)
	{
        if (*input != 32)
        {
            if (*input > 57 || *input < 48)
            {
                ft_printf("ERROR\n");
                ret = NULL;
                return (0);
            }
            if (size == i)
                ret->arr = ft_realloc(ret, i + 1, &size);
            ret->arr[i] = ft_atoi_mod(input, &input);
            ft_printf("Pos:%d ret->arr = %d\n", i, ret->arr[i]);
            i++;
        }
        input++;
        ft_printf("input: %s\n", input);
	}
	ret->top = i;
	return (size);
}

void	push_swap(char *input)
{
	Stack *a, *b;
    int i = 0;
    int size;

    a = ft_stackalloc();
    b = ft_stackalloc();
	size = ft_parseinput(input, a);
	if (size == 0)
		return ;
    b->arr = malloc(sizeof(int) * size);
    b->top = 0;
    while (i < a->top)
    {
        ft_printf("%d\n", a->arr[i]);
        i++;
    }
    ft_logic(a, b);
    i = 0;
    ft_printf("uhhhhhhhh\n\n");
    while (i < b->top)
    {
        ft_printf("%d\n", b->arr[i]);
        i++;
    }
}

int	main()
{
    push_swap("34 3 31 98 92 23");
    return (0);
}
