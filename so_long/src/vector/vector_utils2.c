/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:28:52 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

/*
	void			(*destroy_element)(t_element	*e);
*/

void	__vec_rm_rf(void)
{
	t_element	*current;
	t_element	*prev;

	if (!fthis()->vector)
		return ;
	prev = NULL;
	current = fthis()->vector->begin;
	while (current)
	{
		prev = current;
		current = current->next;
		free_safe((void **)&prev);
	}
	fthis()->vector->begin = NULL;
	fthis()->vector->end = NULL;
	fthis()->vector->size = 0;
}

// Man this one was dificult
void	__vec_rm_val(void *value)
{
	t_element	*current;
	t_element	*prev;

	if (!fthis()->vector || !value)
		return ;
	prev = NULL;
	current = fthis()->vector->begin;
	while (current)
	{
		if (!ft_memcmp(current->value, value, INT_MAX))
		{
			if (fthis()->vector->end == current)
				fthis()->vector->end = prev;
			if (prev)
				prev->next = current->next;
			else
				fthis()->vector->begin = current->next;
			free_safe((void **)&current);
			fthis()->vector->size--;
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	__vec_rm_first(void)
{
	t_element	*first;

	if (!fthis()->vector || fthis()->vector->size == 0)
		return ;
	first = fthis()->vector->begin;
	if (first->next)
		fthis()->vector->begin = first->next;
	else
		fthis()->vector->begin = NULL;
	free_safe((void **)&first);
	fthis()->vector->size--;
}

void	__vec_exec_on_each(void (*fun)(t_element *e, void *v), void *v)
{
	t_element	*current;

	if (!fthis()->vector || !v)
		return ;
	current = fthis()->vector->begin;
	while (current)
	{
		fun(current, v);
		current = current->next;
	}
}

void	__vec_exec_on_index(void (*fun)(t_element *e, void *v),
void *v, int index)
{
	t_element	*current;
	int			i;

	i = 0;
	if (!fthis()->vector || !v)
		return ;
	current = fthis()->vector->begin;
	while (current)
	{
		if (i++ == index)
		{
			fun(current, v);
			return ;
		}
		current = current->next;
	}
}
