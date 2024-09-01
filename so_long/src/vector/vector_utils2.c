#include "../../headers/header.h"


/*
	void			(*destroy_element)(t_element	*e);
*/

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
	free_safe((void**)&current);
}

void	__vec_destructor(void)
{
	fthis()->vector->remove_all();
	free_safe((void**)&fthis()->vector);
}

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
		free_safe((void**)&prev);
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
			object(current->value)->destructor();
			free_safe((void**)&current);
			fthis()->vector->size--;
			current = prev;
		}
		prev = current;
		current = current->next;
	}
}

void	__vec_rm_first()
{
	t_element	*first;

	if (!fthis()->vector || fthis()->vector->size == 0)
		return ;
	first = fthis()->vector->begin;
	if (first->next)
		fthis()->vector->begin = first->next;
	else
		fthis()->vector->begin = NULL;
	free_safe((void**)&first);
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

void	__vec_exec_on_index(void (*fun)(t_element *e, void *v), void *v, int index)
{
	t_element	*current;
	int		i;

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
