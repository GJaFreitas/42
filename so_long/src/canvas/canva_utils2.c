#include "../../headers/header.h"

byte	__draw_pixel(int x, int y, int color);

void	__clear_screen(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			__draw_pixel(x, y, 0);
			x++;
		}
		y++;
	}
}
