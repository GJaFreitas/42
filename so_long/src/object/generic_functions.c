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
	mlx_destroy_image(engine()->mlx,
		   fthis()->object->sprite->img);
	// The only free not protected agaisnt double free
	free(fthis()->object->get_sprite());
}

void	__generic_render(void)
{
	canva()->scale_img(
		fthis()->object->get_sprite(), \
		(t_pos_vector){ fthis()->object->pos.x, fthis()->object->pos.y, \
		fthis()->object->pos.w, fthis()->object->pos.h});
	//mlx_put_image_to_window(engine()->mlx, engine()->win,
			 //fthis()->object->get_sprite()->img, fthis()->object->pos.x, fthis()->object->pos.y);
}

t_sprite	*__generic_get_sprite(void)
{
	return (fthis()->object->sprite);
}
