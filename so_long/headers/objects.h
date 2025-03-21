/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:46:10 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 17:15:29 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "helper_structs.h"
# include "canva.h"
# include "map.h"
# include "vector.h"
# include "../libs/libft/libft.h"

typedef unsigned char					t_byte;

typedef struct s_object					t_object;
typedef struct s_game					t_game;
typedef struct s_player					t_player;
typedef struct s_fireball				t_fireball;
typedef struct s_hud					t_hud;
typedef struct s_door					t_door;
typedef struct s_enemy					t_enemy;
typedef struct s_collectible			t_collectible;
typedef struct s_start					t_start;
typedef struct s_exit					t_exit;
typedef struct s_wall					t_wall;
typedef struct s_menu					t_menu;
typedef struct s_counter				t_counter;

struct s_object
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();
};

struct s_game
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)();
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();

	t_player				*player;
	t_byte					in_menu;
	t_vector				*objects;
	t_vector				*keys;
	t_vector				*mouse;
	t_vector				*to_render;
	t_vector				*to_update;
	t_vector				*to_remove;
	t_map					*maps[128];
	t_byte					walls[1080][1920];
	int						moves;
	t_byte					goodbye;
	void					(*add_obj)(t_object *o);
	void					(*rm_obj)();
	t_object				*(*obj_colision)(
			t_pos_vector pos, t_type *list);
	void					(*startgame)();
	unsigned int			collectibles_num;
};

struct s_player
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();

	void					(*move)(t_pos_vector);
	void					(*attack)();
	unsigned int			collectibles;
};

struct s_fireball
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();

	t_pos_vector			shot_vec;
};

struct s_hud
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)(int which);

	t_sprite				*hpsprite;
	t_sprite				*hpbar;
	t_pos_vector			hpsize;
};

struct s_door
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();

	t_byte					state;
	t_byte					locked_bool;
};

struct s_enemy
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();
};

struct s_collectible
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();

	t_byte					is_render;
};

struct s_start
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();
};

struct s_exit
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();
};

struct s_wall
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();
};

struct s_menu
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)();

	void					(*start)();
	void					(*end)();
};

struct s_counter
{
	t_type					type;
	t_pos_vector			pos;
	double					hp;
	t_sprite				*sprite;

	void					(*render)();
	void					(*update)();
	void					(*destructor)();
	void					(*collision)(t_object*);
	void					(*func_keys)(t_byte *keys);
	void					(*func_mouse)();
	void					(*set_pos)(t_pos_vector);
	void					(*damage)(double);
	t_sprite				*(*get_sprite)(int i);

	t_sprite				*nums[10];
	t_sprite				*bar;
};

t_object				*object(t_object *object);
void					*constructor(size_t size);
void					start_game(void);
t_game					*game(void);
t_object				*new_menu(void);
t_object				*new_bg(void);
t_object				*new_player(float x, float y);;
t_object				*new_enemy(float x, float y);
t_object				*new_collectible(float x, float y);
t_object				*new_exit(float x, float y);
t_object				*new_start(float x, float y);
t_object				*new_wall(float x, float y);
t_object				*new_fireball(t_pos_vector vec);
t_object				*new_hud(void);
t_object				*new_counter(void);

#endif
