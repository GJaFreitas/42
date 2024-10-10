#include "../../headers/header.h"

static unsigned long	hf(const char *str)
{
	unsigned long	hash;
	int		i;
        int 		c;

	hash = 5381;
	i = 0;
	c = str[i++];
	while (c)
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		c = str[i++];
	}
        return (hash);
}

t_hashtable	*new_hashtable(unsigned long size)
{
	t_hashtable	*table;

	table = malloc_safe(sizeof(t_hashtable));
	table->hashf = hf;
	table->size = size;
	table->elements = malloc_safe(sizeof(t_entry *) * size);
	return (table);
}
