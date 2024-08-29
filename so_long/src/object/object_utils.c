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
t_sprite	*__generic_load_sprite(char *path);

// Returns a new instance of an object with variable size
void	*constructor(size_t size)
{
	void	*o;

	o = malloc_safe(size);
	((t_object *)o)->sprite = malloc_safe(sizeof(t_sprite));
	((t_object *)o)->type = OBJECT;
	((t_object *)o)->get_sprite = __generic_load_sprite;
	((t_object *)o)->pos.x = 0;
	((t_object *)o)->pos.y = 0;
	return (o);
}
