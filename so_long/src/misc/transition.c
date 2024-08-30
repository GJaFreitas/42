#include "../../headers/header.h"
#include <unistd.h>


/*
t_sprite	*__load_img(char *texture_name)
{
	t_sprite	*new_sprite;

	new_sprite = malloc_safe(sizeof(t_sprite));
	new_sprite->img = mlx_xpm_file_to_image(engine()->mlx,
				texture_name,
				&new_sprite->width,
				&new_sprite->height);
	new_sprite->address = mlx_get_data_addr(new_sprite->img,
				&new_sprite->bpp,
				&new_sprite->line_length,
				&new_sprite->endian);
	return (new_sprite);
}
*/

static t_sprite	*__create_img(void)
{
	t_sprite	*sprite;

	sprite = malloc_safe(sizeof(t_sprite));
	sprite->width = WIDTH;
	sprite->height = HEIGHT;
	sprite->img = mlx_new_image(engine()->mlx, WIDTH, HEIGHT);
	sprite->address = mlx_get_data_addr(sprite->img, &sprite->bpp, \
				  &sprite->line_length, &sprite->endian);
	return (sprite);
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

/*
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
*/

int	encode_trgb(byte opacity, byte red, byte green, byte blue)
{
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

// TODO: Fadeout function
// Not entirely sure why its not putting the image int the window every loop
void	fadeout(void)
{
	t_sprite	*img;
	t_pos_vector	pos;
	int		alpha;

	alpha = 1;
	pos.x = 0;
	img = __create_img();
	while (alpha <= 255)
	{
		while (pos.x < WIDTH)
		{
			pos.y = 0;
			while (pos.y < HEIGHT)
			{
				__draw_pixel(img, pos.x, pos.y, encode_trgb(alpha, 0, 0, 0));
				pos.y++;
			}
			pos.x++;
		}
		mlx_put_image_to_window(engine()->mlx, engine()->win, img->img, 0, 0);
		printf("alpha: %d\n", alpha);
		usleep(1000000);
		alpha *= 2;
		if (alpha == 256)
			alpha = 255;
	}
	mlx_destroy_image(engine()->mlx, img->img);
	free_safe((void**)&img);
}
