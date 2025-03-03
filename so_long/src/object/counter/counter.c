#include "../../../headers/header.h"

/*
<<<<<<< HEAD
=======
* For ease of programming im limiting the number of collectibles to 9
*/

static void	__counter_destructor(void)
{
	t_counter	*c;
	int		i;

	c = (t_counter *)fthis()->object;
	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(engine()->mlx,
		    c->nums[i]->img);
		free(c->get_sprite(i++));
	}
	mlx_destroy_image(engine()->mlx, c->bar->img);
	free(c->get_sprite(515));
}

// TODO: Add a bar between the two numbers
static void	__counter_render(void)
{
	t_counter	*c;

	c = (t_counter *)fthis()->object;
	canva()->scale_img(
		c->get_sprite(game()->player->collectibles), \
		c->pos);
	canva()->scale_img(
		c->get_sprite(515), \
		(t_pos_vector){c->pos.x + c->pos.w - 20, c->pos.y + 15, c->pos.w * 0.66, c->pos.h * 0.66});
	canva()->scale_img(
		c->get_sprite(game()->collectibles_num), \
		(t_pos_vector){c->pos.x + c->pos.w + 50, c->pos.y, c->pos.w, c->pos.h});
}

static t_sprite	*__counter_get_sprite(int i)
{
	if (i == 515)
		return (((t_counter *)fthis()->object)->bar);
	return (((t_counter *)fthis()->object)->nums[i]);
}

t_object	*new_counter(void)
{
	char		str[32];
	t_counter	*counter;

	counter = constructor(sizeof(t_counter));
	counter->type = COUNTER;
	counter->render = __counter_render;
	counter->get_sprite = __counter_get_sprite;
	counter->destructor = __counter_destructor;
	counter->pos.x = 1600;
	counter->pos.y = 5;
	counter->pos.w = canva()->scale_factor;
	counter->pos.h = canva()->scale_factor;
	ft_strlcpy(str, "textures/number0.xpm", 32);
	while ((str[15] - '0') < 10)
	{
		counter->nums[str[15] - '0'] = canva()->load_img(str);
		str[15] += 1;
	}
	counter->bar = canva()->load_img("textures/bar.xpm");
	return ((t_object *)counter);
}
