#ifndef OBJECTS_H
# define OBJECTS_H

# include "e_type.h"
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

// Position in relation to the top left corner of screen
typedef struct pos_vector
{
	int	x;
	int	y;
}	t_pos_vector;

struct s_object
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_game
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	void			*objects;
	void			*keys;
	void			*to_render;
	void			*interactions;
	void			(*start)();
};

struct s_player
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
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

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_door
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
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

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();
};

struct s_menu
{
	t_type			type;
	t_pos_vector		pos;
	double			hp;

	void			(*render)();
	void			(*update)();
	void			(*destructor)();
	void			(*collision)(t_object*);
	void			(*func_key)(t_object*);
	void			(*func_mouse)(t_object*);
	void			(*set_pos)(t_pos_vector);
	void			(*damage)(double);
	t_sprite		*(*get_sprite)();

	void			(*start)();
	void			(*end)();
};


void	*constructor(size_t size);
void	start_game(void);

#endif
