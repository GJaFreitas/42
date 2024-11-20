#ifndef VECTOR_H
# define VECTOR_H

// My own implementation of C++ vectors
// Basically and array of void* that can manage its own memory
// and do a bunch of other cool stuff

# include "helper_structs.h"

typedef struct s_vector t_vector;
typedef struct s_element t_element;

struct s_element
{
	void			*value;
	t_type			type;
	struct s_element	*next;
};

// Destroy -> destroys instance
// Remove all -> destroys all elements in instance
// Remove value -> destroys specific value
struct s_vector
{
	t_element		*begin;
	t_element		*end;
	int				size;
	t_element		*(*add)(void	*value);
	void			*(*get)(int	index);
	t_element		*(*set_at_index)(int index, void *value);
	void			(*remove_index)(int index);
	void			(*remove_first)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	void			(*for_index)(void (*fun)(t_element *e, void *v), void *o, int index);
	void			(*remove_value)(void *value);
	void			(*remove_all)(void);
	void			(*remove_this)(t_element *e);
	void			(*destroy)();
	void			(*sort)();
};

t_vector	*vector(t_vector *vector);
void		*new_vector(void);

#endif
