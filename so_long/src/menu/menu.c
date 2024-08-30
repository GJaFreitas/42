#include "../../headers/header.h"

static void	__render_menu(void)
{
	canva()->scale_img(
		fthis()->object->get_sprite(), \
		(t_pos_vector){ fthis()->object->pos.x, fthis()->object->pos.y, \
		WIDTH, HEIGHT});
	//mlx_put_image_to_window(engine()->mlx, engine()->win,
			 //fthis()->object->get_sprite()->img, fthis()->object->pos.x, fthis()->object->pos.y);
}

// Returns a new instance of the menu object
t_object	*new_menu()
{
	t_menu	*menu;

	menu = constructor(sizeof(t_menu));
	menu->render = __render_menu;
	menu->func_keys = NULL;
	menu->func_mouse = NULL;
	menu->pos.x = 0;
	menu->pos.y = 0;
	menu->sprite = canva()->load_img("textures/menu.xpm");
	return ((t_object *)menu);
}

/*
void	menu_buttons(byte *keys, byte event)
{
}
*/

