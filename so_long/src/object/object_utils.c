#include "../../headers/header.h"

/*
struct s_object
{
	t_type			type;
	t_vector		pos;
	double			hp;
	t_sprite		*sprite;

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
void	__generic_destructor();

static t_sprite	*__generic_get_sprite()
{
	return (fthis()->object->sprite);
}

// Returns a new instance of an object with variable size
void	*constructor(size_t size)
{
	t_object	*o;

	o = malloc_safe(size);
	o->type = OBJECT;
	o->get_sprite = __generic_get_sprite;
	o->destructor = __generic_destructor;
	o->pos.x = 0;
	o->pos.y = 0;
	return (o);
}
