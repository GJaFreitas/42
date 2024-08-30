#include "../../headers/header.h"


void	__add_obj(t_object *o)
{
	if (!o)
		return ;
	vector(game()->objects)->add(o);
	if (o->func_keys != NULL)
		vector(game()->keys)->add(o);
	if (o->func_mouse != NULL)
		vector(game()->mouse)->add(o);
	if (o->render != NULL)
		vector(game()->to_render)->add(o);
}
