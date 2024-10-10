#include "../../headers/header.h"

int	__insert(const char *key, void *value, t_hashtable *self)
{
	t_entry		*e;
	unsigned long	index;

	if (!key || !value || !self)
		return (0);
	index = hti(self, key);
	if (self->lookup(key, self) != NULL)
		return (0);
	e = malloc_safe(sizeof(t_entry));
	e->value = value;
	e->key = ft_strdup(key);
	self->elements[index] = e;
	return (1);
}

void	*__lookup(const char *key, t_hashtable *self)
{
	t_entry		*tmp;

	if (!key || !self)
		return (NULL);
	tmp = self->elements[hti(self, key)];
	while (tmp && ft_strncmp(key, tmp->key, 128))
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp->value);
}

void	__remove(const char *key, t_hashtable *self)
{
	t_entry		*tmp;
	t_entry		*prev;
	unsigned long	index;

	if (!key || !self)
		return ;
	index = hti(self, key);
	tmp = self->elements[index];
	prev = NULL;
	while (tmp && ft_strncmp(key, tmp->key, 128))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (!prev)
		self->elements[index] = tmp->next;
	else
		prev->next = tmp->next;
	free(tmp->value);
	free(tmp->key);
	free(tmp);
}

void	*__pull_out(const char *key, t_hashtable *self)
{
	void		*ret;
	t_entry		*tmp;
	t_entry		*prev;
	unsigned long	index;

	if (!key || !self)
		return (NULL);
	index = hti(self, key);
	tmp = self->elements[index];
	prev = NULL;
	while (tmp && ft_strncmp(key, tmp->key, 128))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return (NULL);
	if (!prev)
		self->elements[index] = tmp->next;
	else
		prev->next = tmp->next;
	ret = tmp->value;
	free(tmp->key);
	free(tmp);
	return (ret);
}

// You have to pass the destructor of the thing you
// are storing in the hashtable
void	__destroy(t_hashtable *self, void (*boom)(void *))
{
	unsigned long	i;
	t_entry		*tmp;
	t_entry		*prev;

	i = 0;
	while (i < self->size)
	{
		tmp = self->elements[i];
		while (tmp)
		{
			boom(tmp->value);
			prev = tmp;
			tmp = tmp->next;
			free(prev->key);
			free(prev);
		}
		i++;
	}
	free(self->elements);
	free(self);
}
