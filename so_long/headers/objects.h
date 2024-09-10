#ifndef OBJECTS_H
# define OBJECTS_H

# include "helper_structs.h"
# include "canva.h"
# include "map.h"
# include "vector.h"
# include "../libs/libft/libft.h"

typedef unsigned char byte;

typedef struct s_object t_object;
typedef struct s_game t_game;
typedef struct s_player t_player;
typedef struct s_fireball t_fireball;
typedef struct s_hud t_hud;
typedef struct s_door t_door;
typedef struct s_enemy t_enemy;
typedef struct s_collectible t_collectible;
typedef struct s_start t_start;
typedef struct s_exit t_exit;
typedef struct s_wall t_wall;
typedef struct s_menu t_menu;

struct s_object
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_game
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)();
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	t_player		*player;
	byte			in_menu;
	t_vector			*objects;
	t_vector			*keys;
	t_vector			*mouse;
	t_vector			*to_render;
	t_vector			*to_update;
	t_vector			*to_remove;
	t_map				*maps[128];
	byte				walls[1080][1920];
	int				moves;
	void			(*add_obj)(t_object *o);
	void			(*rm_obj)();
	void			(*startgame)();
	byte			fireball;
};

struct s_player
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	void			(*move)(t_pos_vector);
	void			(*attack)();
};

struct s_fireball
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	t_pos_vector		shot_vec;
};

struct s_hud
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_door
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	byte			state;
	byte			locked_bool;
};

struct s_enemy
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_collectible
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_start
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_exit
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_wall
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_menu
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;
	t_sprite		*sprite;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_keys)(byte *keys);
	void			(*func_mouse)();
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	void			(*start)();
	void			(*end)();
};


t_object	*object(t_object *object);
void	*constructor(size_t size);
void	start_game(void);
t_game	*game(void);
t_object	*new_menu();
t_object	*new_bg();
t_object	*new_player(float x, float y);;
t_object	*new_enemy(float x, float y);
t_object	*new_collectible(float x, float y);
t_object	*new_exit(float x, float y);
t_object	*new_start(float x, float y);
t_object	*new_wall(float x, float y);
t_object	*new_fireball(t_pos_vector vec);

#endif
