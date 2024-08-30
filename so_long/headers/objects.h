#ifndef OBJECTS_H
# define OBJECTS_H

# include "helper_structs.h"
# include "canva.h"
# include "vector.h"
# include "../libs/libft/libft.h"

typedef unsigned char byte;

typedef struct s_object t_object;
typedef struct s_game t_game;
typedef struct s_player t_player;
typedef struct s_hud t_hud;
typedef struct s_door t_door;
typedef struct s_enemy t_enemy;
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

	byte			players;
	byte			in_menu;
	t_vector			*objects;
	t_vector			*keys;
	t_vector			*mouse;
	t_vector			*to_render;
	t_vector			*interactions;
	void			(*add_obj)(t_object *o);
	void			(*startgame)();
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
	void			(*attack)(); // will have to pass info on the mouse?
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

#endif
