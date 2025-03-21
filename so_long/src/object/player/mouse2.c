/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 14:19:47 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

#ifndef DASH_DISTANCE
# define DASH_DISTANCE 15
#endif

#ifndef DASH_COOLDOWN
# define DASH_COOLDOWN 0.5
#endif

int	__cooldown(clock_t *last, clock_t current, float cooldown)
{
	double		time_past;

	time_past = (double)(current - *last) / CLOCKS_PER_SEC;
	if (time_past > cooldown)
	{
		*last = current;
		return (1);
	}
	return (0);
}

// Calculates the direction and then shoots the
// fireball taking care to not divide by 0
void	__mouse_left(void)
{
	static clock_t	init;
	t_pos_vector	vec;

	vec.x = (engine()->mouse.x - game()->player->pos.x);
	vec.y = (engine()->mouse.y - game()->player->pos.y);
	__vec_normalization(&vec.x, &vec.y);
	vec.x *= FIREBALL_SPEED;
	vec.y *= FIREBALL_SPEED;
	if (__cooldown(&init, clock(), FIREBALL_COOLDOWN))
		game()->add_obj(new_fireball(vec));
}
/*
int	__cooldown(clock_t *last, clock_t current, float cooldown);

static int	__dash_check(t_pos_vector vec, int mult)
{
	if (collision_check_x(game()->player->pos, vec.x * mult)\
	&& collision_check_y(game()->player->pos, vec.y * mult))
		return (1);
	return (0);
}

static void	__dash(t_pos_vector vec)
{
	t_player	*p;
	int		i;

	p = game()->player;
	i = DASH_DISTANCE;
	while (__dash_check(vec, (i--)))
		;
	p->pos.x -= vec.x * i;
	p->pos.y -= vec.y * i;
}

// Shoots in all 8 cardinal directions, yes 8
static void	__shoots(void)
{
	int	speed;

	speed = FIREBALL_SPEED * 2;
	game()->add_obj(new_fireball((t_pos_vector){speed, speed, 0, 0}));
	game()->add_obj(new_fireball((t_pos_vector){-speed, -speed, 0, 0}));
	game()->add_obj(new_fireball((t_pos_vector){-speed, speed, 0, 0}));
	game()->add_obj(new_fireball((t_pos_vector){speed, -speed, 0, 0}));
	game()->add_obj(new_fireball((t_pos_vector){speed, 0, 0, 0}));
	game()->add_obj(new_fireball((t_pos_vector){0, speed, 0, 0}));
	game()->add_obj(new_fireball((t_pos_vector){0, 0, 0, 0}));
	game()->add_obj(new_fireball((t_pos_vector){speed, speed, 0, 0}));
}

void	__mouse_right()
{
	static clock_t	init;

	if (__cooldown(&init, clock(), FIREBALL_COOLDOWN * 4))
		__shoots();
}
*/
