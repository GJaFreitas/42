#include "../../../headers/header.h"

static void	__menu_buttons()
{
	if (engine()->mouse.x >= 777 && engine()->mouse.x <= 1490 && \
			engine()->mouse.y >= 490 && engine()->mouse.y <= 632)
	{
		game()->startgame();
	}
}

static void	__keys(byte *keys)
{
	if (keys[0])
		fadeout();
}

// Returns a new instance of the menu object
t_object	*new_menu()
{
	t_menu	*menu;

	game()->in_menu = 1;
	menu = constructor(sizeof(t_menu));
	menu->pos.w = WIDTH;
	menu->pos.h = HEIGHT;
	menu->sprite = canva()->load_img("textures/menu.xpm");
	menu->func_mouse = __menu_buttons;
	menu->func_keys = __keys;
	return ((t_object *)menu);
}

/*
void	menu_buttons(byte *keys, byte event)
{
}
*/

