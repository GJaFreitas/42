#include "../includes/lib.h"

t_square	*make_square(short x, short y, int size, int color)
{
	t_square *s;

	s = malloc(sizeof(struct s_square));
	s->x = x;
	s->y = y;
	s->size = size;
	s->color = color;
	return (s);
}

void	render_square(t_square square, int x_offset, int y_offset, t_img img)
{
	int	x = x_offset;
	int	y = y_offset;

	while (y < (y_offset + square.size) && y <= img.h)
	{
		while (x < (x_offset + square.size) && x <= img.w)
		{
			pixel_put_optimization(img, x, y, square.color);
			x++;
		}
		x = x_offset;
		y++;
	}
}

// Draws a single square
void	draw_square(int x, int y, int size, int color, t_data data)
{
	t_square	*square;
	t_square	s;

	s.size = 10;
	s.x = 150;
	s.y = 150;
	s.color = encode_rgb(254, 140, 1);
	square = make_square(x, y, size, color);
	render_square(s, x, y, *(data->img));
	free(square);
}

void	start_screen(t_data data)
{
	t_square	*square;

	square = make_square(WIDTH>>1, LENGHT>>1, 50, encode_rgb(255, 0, 0));
	render_square(*square, square->x, square->y, *(data->img));
	walk(0, (void*)square);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img->img_ptr, 0, 0);
}

void	walk(int keycode, void *data)
{
	static void	*square;
	if (keycode == XK_w)
	{
		color_screen((t_data)data, 0);
		((t_square*)square)->y -= 50;
		// Evil ass casts right here, why? because i didnt feel like chaging the other fucntions
		render_square(*((t_square*)square), ((t_square*)square)->x, ((t_square*)square)->y, *(((t_data)data)->img));
	}
	if (keycode == XK_a)
	{
		color_screen((t_data)data, 0);
		((t_square*)square)->x -= 50;
		render_square(*((t_square*)square), ((t_square*)square)->x, ((t_square*)square)->y, *(((t_data)data)->img));
	}
	if (keycode == XK_s)
	{
		color_screen((t_data)data, 0);
		((t_square*)square)->y += 50;
		render_square(*((t_square*)square), ((t_square*)square)->x, ((t_square*)square)->y, *(((t_data)data)->img));
	}
	if (keycode == XK_d)
	{
		color_screen((t_data)data, 0);
		((t_square*)square)->x += 50;
		render_square(*((t_square*)square), ((t_square*)square)->x, ((t_square*)square)->y, *(((t_data)data)->img));
	}
	if (keycode == 0)
	{
		// This almost feels ilegal but oh well
		// using void* to the max here, with one argument i can
		// pass either the square or the t_data pointer
		square = data;
		return ;
	}
	if (keycode == -1)
		// My love of void* cannot be expressed trough the English language
		// except perhaps trough embarassing poetry
		free(square);
}
