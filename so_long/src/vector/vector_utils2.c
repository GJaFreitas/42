#include "../../headers/header.h"


/*
	void			(*destroy_element)(t_element	*e);
*/

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
			current->destroy(current);
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
	first->destroy(first);
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
