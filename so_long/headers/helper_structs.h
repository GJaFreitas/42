/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:58:29 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 18:31:38 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_STRUCTS_H
# define HELPER_STRUCTS_H

typedef enum e_type
{
	OBJECT = 0,
	MENU,
	BG,
	MAP,
	WALL,
	DOOR,
	START,
	EXIT,
	PLAYER,
	FIREBALL,
	ENEMY,
	COLLECTIBLE,
	COUNTER,
	HUD,
	GAME,
}	t_type;

typedef struct pos_vector
{
	float	x;
	float	y;
	float	w;
	float	h;
}	t_pos_vector;

#endif
