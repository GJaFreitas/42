#include "../../headers/header.h"

int	__mouse_release(int key, int x, int y)
{
	mlx_mouse_get_pos(engine()->mlx, engine()->win, &x, &y);
	engine()->mouse.x = x;
	engine()->mouse.y = y;
	(void)key;
	return (0);
}
