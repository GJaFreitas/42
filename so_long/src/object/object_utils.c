#include "../../headers/header.h"

/*
struct s_object
{
	t_type			type;
	t_vector		pos;
	double			hp;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};
*/

// Returns a new instance of an object with variable size
void	*constructor(size_t size)
{
	void	*o;

	o = malloc_safe(size);
	((t_object *)o)->type = OBJECT;
	return (o);
}
