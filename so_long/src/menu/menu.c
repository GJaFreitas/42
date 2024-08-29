#include "../../headers/header.h"

static void	__render_menu(void)
{
	canva()->draw_img(
		fthis()->object->sprite,
		   fthis()->object->pos.x,
		   fthis()->object->pos.x);
}

// Returns a new instance of the menu object
t_object	*new_menu()
{
	t_menu	*menu;

	menu = constructor(sizeof(t_menu));
	menu->render = __render_menu;
	menu->func_key = NULL;
	menu->sprite = canva()->load_img("textures/menu.xpm");
	return ((t_object *)menu);
}

/*
void	menu_buttons(byte *keys, byte event)
{
}
*/

