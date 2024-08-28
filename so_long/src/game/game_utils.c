#include "../../headers/header.h"


void	__add_obj(t_object *o)
{
	if (!o)
		return ;
	vector(game()->objects)->add(o);
	if (o->func_key)
		vector(game()->keys)->add(o);
	if (o->render)
		vector(game()->to_render)->add(o);
}
