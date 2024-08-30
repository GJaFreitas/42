#include "../../headers/header.h"


/*
	void			(*remove_this)(t_element	*e);
	void			(*remove_index)(int index);
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	void			(*remove_value)(void *value);
	void			(*remove_all)(void);;
	int				(*destroy)();
	void			(*destroy_element)(t_element	*e);
*/

// I need more lines to make this accept index = 0
// so ill make another function to remove the first element
// TODO: THIS IS BROKEN BECAUSE OF THE NEW free_safe FUNCTION
void	__vec_rm_index(int index)
{
	t_element	*current;
	t_element	*prev;
	int		i;

	i = 0;
	if (!fthis()->vector || index > fthis()->vector->size || index < 1)
		return ;
	current = fthis()->vector->begin;
	prev = NULL;
	while (current)
	{
		if (index == i++)
		{
			if (current->next && prev)
				prev->next = current->next;
			else if (prev)
				prev->next = NULL;
			free_safe((void**)&current);
			fthis()->vector->size--;
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	__destroy_element(void **e)
{
	free_safe(e);
}

// if vector is empty then put new element at begining
// else put it after the end
// the end is now the new element (in first case it is also the begining)
// element index is the previus vector size
// vector size goes up by one 
t_element	*__vec_add(void *value)
{
	t_element	*e;

	if (!fthis()->vector || !value)
		return (NULL);
	e = malloc_safe(sizeof(t_element));
	e->value = value;
	e->next = NULL;
	if (!fthis()->vector->size)
	{
		fthis()->vector->begin = e;
		fthis()->vector->end = e;
	}
	else
		fthis()->vector->end->next = e;
	e->index = fthis()->vector->size;
	fthis()->vector->size++;
	return (e);
}

// Ill allow value to be NULL simply because i might want to set a certain value
// to NULL and its not really a problem to set it as NULL since it will be
// free before it is set
t_element	*__vec_set_value_index(int index, void *value)
{
	t_element	*current;
	int		i;

	i = 0;
	if (!fthis()->vector || index > fthis()->vector->size || index < 0)
		return (NULL);
	current = fthis()->vector->begin;
	while (current)
	{
		if (i == index)
		{
			object(current->value)->destructor();
			free_safe(&current->value);
			current->value = value;
			return (current);
		}
		current = current->next;
		i++;
	}
	return (current);
}

void	*__vec_get_val(int index)
{
	t_element	*e;
	int		i;

	i = 0;
	if (!fthis()->vector || index > fthis()->vector->size || index < 0)
		return (NULL);
	e = fthis()->vector->begin;
	while (e)
	{
		if (i == index)
			return (e->value);
		e = e->next;
		i++;
	}
	return (NULL);
}
