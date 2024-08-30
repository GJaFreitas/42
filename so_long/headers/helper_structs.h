#ifndef ENUM_H
# define ENUM_H

typedef enum e_type
{
	OBJECT,
	GAME,
	PLAYER,
	HUD,
	DOOR,
	ENEMY,
	WALL,
	MENU,
}	t_type;

typedef struct pos_vector
{
	float	x;
	float	y;
	float	w;
	float	h;
}	t_pos_vector;

#endif
