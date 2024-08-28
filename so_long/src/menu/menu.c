#include "../../headers/header.h"

void	__render_menu(void);

t_object	*new_menu()
{
	t_menu	*menu;

	menu = constructor(sizeof(t_menu));
	menu->render = __render_menu;
	menu->sprite = canva()->load_img("textures/menu.xmp");
	menu->pos.x = 0;
	menu->pos.y = 0;
	return ((t_object *)menu);
}

/*
void	menu_buttons(byte *keys, byte event)
{
}
*/

void	__render_menu()
{
	canva()->draw_img(
		fthis()->object->sprite,
		   fthis()->object->pos.x,
		   fthis()->object->pos.x);
}
