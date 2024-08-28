#include "../../headers/header.h"

static void	__menu_start(void)
{
}

static void	__menu_end(void)
{
}

static void	__render_menu(void)
{
}

t_object	*new_menu(void)
{
	t_menu	*menu;

	menu = constructor(sizeof(t_menu));
	menu->render = __render_menu;
	menu->start = __menu_start;
	menu->end = __menu_end;
	return ((t_object *)menu);
}
