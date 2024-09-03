#ifndef ENUM_H
# define ENUM_H

typedef enum e_type
{
	OBJECT = 0,
	MENU,
	BG,
	WALL,
	DOOR,
	PLAYER,
	PLAYER2,
	ENEMY,
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
