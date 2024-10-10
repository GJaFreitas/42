#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct s_hashtable t_hashtable;
typedef struct s_entry t_entry;

typedef unsigned long (hashfunction)(const char *);

struct s_entry
{
	char	*key;
	void	*value;
	t_entry	*next;
};

struct s_hashtable
{
	unsigned long	size;
	hashfunction	*hashf;
	t_entry		**elements;

	int	(*insert)(const char *key, void *value, t_hashtable *self);
	void	(*destroy)(t_hashtable *self);
	void	(*remove)(const char *key, t_hashtable *self);
	void	*(*lookup)(const char *key, t_hashtable *self);
	void	*(*pop)(const char *key, t_hashtable *self);
};

t_hashtable	*new_hashtable(unsigned long size);

#endif
