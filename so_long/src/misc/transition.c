#include "../../headers/header.h"
#include <unistd.h>


static t_sprite	*__create_img(void)
{
	t_sprite	*img;

	img = malloc_safe(sizeof(t_sprite));
	img = mlx_new_image(engine()->mlx, WIDTH, HEIGHT);
	img->address = mlx_get_data_addr(img->img, &img->bpp, \
				  &img->line_length, &img->endian);
	return (img);
}

static byte	__draw_pixel(t_sprite *img, int x, int y, int color)
{
	char		*screen;

	if (color == COLOR_TRANSPARENT)
		return (1);
	if (x >= canva()->data.width || y >= canva()->data.height
     		|| x < 0 || y < 0)
		return (0);
	screen = img->address + (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)screen = color;
	return (1);
}

static void	__draw_line_hor(t_sprite *img, int y)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		__draw_pixel(img, x, y, 0);
		x++;
	}
}

static void	__draw_line_ver(t_sprite *img, int x)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		__draw_pixel(img, x, y, 0);
		y++;
	}
}

void	fadeout(void)
{
	t_sprite	*img;
	t_pos_vector	pos;

	pos.x = 0;
	pos.y = 0;
	pos.w = WIDTH - 1;
	pos.h = HEIGHT - 1;
	img = __create_img();
	while (pos.x < WIDTH)
	{
		__draw_line_hor(img, pos.y);
		__draw_line_hor(img, pos.h);
		__draw_line_ver(img, pos.x);
		__draw_line_ver(img, pos.w);
		mlx_put_image_to_window(engine()->mlx, engine()->win, img, 0, 0);
		pos.x++;
		pos.y++;
		pos.h--;
		pos.w--;
		usleep(10);
		
	}
	game()->render();
	mlx_destroy_image(engine()->mlx, img);
	free_safe((void**)&img);
}
