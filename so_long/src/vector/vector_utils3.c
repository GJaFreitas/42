/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 15:29:13 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/header.h"

void	__remove_this(t_element *e)
{
	t_element	*current;
	t_element	*prev;

	current = fthis()->vector->begin;
	prev = current;
	while (current != e && current)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (prev != current)
		prev->next = current->next;
	else
		fthis()->vector->begin = current->next;
	fthis()->vector->size--;
	free_safe((void **)&current);
}

void	__vec_destructor(void)
{
	fthis()->vector->remove_all();
	free_safe((void **)&fthis()->vector);
}
