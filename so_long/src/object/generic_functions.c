#include "../../headers/header.h"

/*

void	*constructor(size_t size)
{
	t_object	*o;

	o = malloc_safe(size);
	o->type = OBJECT;
	o->get_sprite = __generic_get_sprite;
	o->pos.x = 0;
	o->pos.y = 0;
	return (o);
}
*/

void	__generic_destructor(void)
{
	mlx_destroy_image(engine()->mlx, \
		   fthis()->object->sprite->img);
	free(fthis()->object->get_sprite());
}

void	__generic_render(void)
{
	canva()->scale_img( \
		fthis()->object->get_sprite(), \
		fthis()->object->pos);
}

t_sprite	*__generic_get_sprite(void)
{
	return (fthis()->object->sprite);
}
