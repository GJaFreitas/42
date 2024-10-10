#include "../../headers/header.h"

int	__insert(const char *key, void *value, t_hashtable *self);
void	*__lookup(const char *key, t_hashtable *self);
void	__remove(const char *key, t_hashtable *self);
void	*__pull_out(const char *key, t_hashtable *self);
void	__destroy(t_hashtable *self, void (*boom)(void *));

// No this isnt an iterator its the hashtable index
unsigned long	hti(t_hashtable *ht, const char *key)
{
	unsigned long	index;

	index = ht->hashf(key) % ht->size;
	return (index);
}

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

// Creates a new instance of a hashtable
t_hashtable	*new_hashtable(unsigned long size)
{
	t_hashtable	*table;

	table = malloc_safe(sizeof(t_hashtable));
	table->hashf = hf;
	table->size = size;
	table->elements = malloc_safe(sizeof(t_entry *) * size);
	table->insert = __insert;
	table->lookup = __lookup;
	table->pop = __pull_out;
	table->remove = __remove;
	table->destroy = __destroy;
	return (table);
}
