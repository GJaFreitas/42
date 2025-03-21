/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:34:42 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

// Returns 0 if a comes after b
static int	__compare_obj(void *a, void *b)
{
	return ((((t_object *)a)->type < ((t_object *)b)->type));
}

static void	front_back_split(t_element *source,
t_element **frontRef, t_element **backRef)
{
	t_element	*fast;
	t_element	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

static t_element	*__sorted_merge(int (*compare)(void *a, void *b),
t_element *a, t_element *b)
{
	t_element	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((*compare)(a->value, b->value))
	{
		result = a;
		result->next = __sorted_merge(compare, a->next, b);
	}
	else
	{
		result = b;
		result->next = __sorted_merge(compare, a, b->next);
	}
	return (result);
}

static void	__vec_mergesort(t_element **headRef,
int (*compare)(void *a, void *b))
{
	t_element	*head;
	t_element	*a;
	t_element	*b;

	head = *headRef;
	if ((head == NULL) || (head->next == NULL))
		return ;
	front_back_split(head, &a, &b);
	__vec_mergesort(&a, compare);
	__vec_mergesort(&b, compare);
	*headRef = __sorted_merge(compare, a, b);
}

void	__vec_sort(void)
{
	return ;
	__vec_mergesort(&fthis()->vector->begin, __compare_obj);
}
