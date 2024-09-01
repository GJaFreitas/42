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
			if (prev)
				prev->next = current->next;
			else
				fthis()->vector->begin = current->next;
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

void	__ordered_add(t_element *e)
{
	t_element	*current;
	t_element	*prev;

	current = fthis()->vector->begin;
	prev = current;
	while (current)
	{
		if (current->type < e->type)
		{
			prev = current;
			current = current->next;
		}
		else
		{
			prev->next = e;
			e->next = current;
			return ;
		}
	}
	prev->next = e;
	e->next = current;
}

t_element	*__vec_add(void *value)
{
	t_element	*e;

	if (!fthis()->vector || !value)
		return (NULL);
	e = malloc_safe(sizeof(t_element));
	e->value = value;
	e->next = NULL;
	e->type = ((t_object*)value)->type;
	if (!fthis()->vector->size)
	{
		fthis()->vector->begin = e;
		fthis()->vector->end = e;
	}
	else
		__ordered_add(e);
	//fthis()->vector->end->next = e;
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
