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

static int	*ft_realloc(int *arr, int size)
{
	int	*ret;
	int	i;

	ret = malloc(size + 1);
	while (size)
	{
		ret[i] = arr[i];
		i++;
		size--;
	}
	free(arr);
	return (ret);
}

static Stack	*ft_parseinput(char *input)
{
	Stack	*ret;
	int	count;

	count = 0;
	while (*input)
	{
		if (*input != 32 || (*input > 57 || *input < 48))
		{
			ft_printf("ERROR\n");
			return (NULL);
		}
		ret->arr = ft_realloc(ret->arr, count);
		ret->arr[count] = ft_atoi(input);
		count++;
		input++;
	}
	ret->size = count;
	return (ret);
}

void	push_swap(char *input)
{
	Stack *a, *b;

	a = ft_parseinput(input);
	if (a == NULL)
		return ;
}
