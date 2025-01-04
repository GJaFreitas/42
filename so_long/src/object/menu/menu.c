#include "../../../headers/header.h"

static void	__menu_buttons(void)
{
	if (engine()->mouse.x >= 777 && engine()->mouse.x <= 1490 && \
			engine()->mouse.y >= 490 && engine()->mouse.y <= 632)
	{
		vector(game()->to_remove)->add(fthis()->object);
		game()->startgame();
	}
}

// Returns a new instance of the menu object
t_object	*new_menu(void)
{
	t_menu	*menu;

	game()->in_menu = 1;
	menu = constructor(sizeof(t_menu));
	menu->type = MENU;
	menu->pos.w = WIDTH;
	menu->pos.h = HEIGHT;
	menu->sprite = canva()->load_img("textures/menu.xpm");
	menu->func_mouse = __menu_buttons;
	return ((t_object *)menu);
}
