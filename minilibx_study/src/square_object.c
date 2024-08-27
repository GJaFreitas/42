#include "../includes/lib.h"

#define UP	'y' - 50
#define DOWN	'y' + 50
#define LEFT	'x' - 50
#define RIGHT	'x' + 50

static void	draw(o_square s);
static void	s_walk(o_square *s, int key);
static void	s_color_change(o_square *s, int color);
static void	start_square(o_square *s);
static void	s_shoot(o_square *s);

void	constructor(o_square *s, t_img canvas)
{
	s->turn = 0;
	s->shoot = s_shoot;
	s->canvas = canvas;
	s->start = start_square;
	s->walk = s_walk;
	s->change_color = s_color_change;
	s->pos.x = 0;
	s->pos.y = 0;
	s->size = 50;
	s->color = encode_rgb(254, 254, 254);
}

static void	s_shoot(o_square *s)
{
	if (s->turn == UP)
		return ;
}

static void	setpos_y(o_square *s, int num)
{
	s->turn = 'y' + num;
	if (s->pos.y + num >= 0 && s->pos.y + num < s->canvas.h)
		s->pos.y += num;
}

static void	setpos_x(o_square *s, int num)
{
	s->turn = 'x' + num;
	if (s->pos.x + num >= 0 && s->pos.x + num < s->canvas.w)
		s->pos.x += num;
}

static void	start_square(o_square *s)
{
	draw(*s);
}

static void	draw(o_square s)
{
	int	x = s.pos.x;
	int	y = s.pos.y;

	while (y >= 0 && y < (s.pos.y + s.size) && y < s.canvas.h)
	{
		while (x >= 0 && x < (s.pos.x + s.size) && x < s.canvas.w)
		{
			pixel_put_optimization(s.canvas, x, y, s.color);
			x++;
		}
		x = s.pos.x;
		y++;
	}
}

static void	s_walk(o_square *s, int key)
{
	if (key == XK_w)
	{
		clear_screen(NULL);
		setpos_y(s, -50);
	}
	if (key == XK_a)
	{
		clear_screen(NULL);
		setpos_x(s, -50);
	}
	if (key == XK_s)
	{
		clear_screen(NULL);
		setpos_y(s, 50);
	}
	if (key == XK_d)
	{
		clear_screen(NULL);
		setpos_x(s, 50);
	}
	draw(*s);
	render(NULL);
}

static void	s_color_change(o_square *s, int color)
{
	s->color = color;
}
