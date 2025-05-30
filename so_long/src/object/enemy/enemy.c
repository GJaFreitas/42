/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:19:39 by gjacome-          #+#    #+#             */
/*   Updated: 2025/04/24 15:29:32 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/header.h"

#ifndef ENEMY_SPEED
# define ENEMY_SPEED 12
#endif

t_pos_vector	__calc_vec(t_enemy *e, t_pos_vector *vec);
void			__get_vec(t_enemy *e, t_pos_vector *vec);
int				__check_wall(t_enemy *e, t_pos_vector vec);
t_list			*astar(t_pos_vector start, t_pos_vector target);

static int	__cooldown(clock_t *last, clock_t current)
{
	double		time_past;

	time_past = (double)(current - *last) / CLOCKS_PER_SEC;
	if (time_past > 0.5)
	{
		*last = current;
		return (1);
	}
	return (0);
}

void	placebo(void *p)
{
	(void)p;
	return ;
}

// Pathfinding and attacking
static void	__update_enemy(void)
{
	static clock_t	init;
	t_pos_vector	direction;
	t_enemy			*e;

	e = (t_enemy *)fthis()->object;
	if (e->hp <= 0)
		return (vector(game()->to_remove)->add(e), (void)69);
	if (__cooldown(&init, clock())
		&& game()->obj_colision(e->pos, (t_type[]){PLAYER, 0}))
		game()->player->hp -= 25;
	direction = __calc_vec(e, &game()->player->pos);
	if (collision_check_x(e->pos, -direction.x * (ENEMY_SPEED * 1.05)))
		e->pos.x += -direction.x * ENEMY_SPEED;
	if (collision_check_y(e->pos, -direction.y * (ENEMY_SPEED * 1.05)))
		e->pos.y += -direction.y * ENEMY_SPEED;
}

static void	__destructor_enemy(void)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)fthis()->object;
	mlx_destroy_image(engine()->mlx, enemy->sprite->img);
	free(enemy->get_sprite());
}

t_object	*new_enemy(float x, float y)
{
	t_enemy	*enemy;

	enemy = constructor(sizeof(t_enemy));
	enemy->hp = 100;
	enemy->type = ENEMY;
	enemy->sprite = canva()->load_img("textures/alien.xpm");
	enemy->pos.w = canva()->scale_factor_e;
	enemy->pos.h = canva()->scale_factor_e;
	enemy->pos.x = x * canva()->scale_factor;
	enemy->pos.y = y * canva()->scale_factor;
	enemy->update = __update_enemy;
	enemy->destructor = __destructor_enemy;
	return (object((t_object *)enemy));
}
