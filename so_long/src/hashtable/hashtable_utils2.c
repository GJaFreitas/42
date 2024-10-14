#include "../../headers/header.h"

int	__contains(const char *key, t_hashtable *self)
{
	t_entry		*tmp;

	if (!key || !self)
		return (0);
	tmp = self->elements[hti(self, key)];
	while (tmp && ft_strncmp(key, tmp->key, 128))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	return (1);
}
