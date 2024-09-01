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
	ENEMY,
	HUD,
	GAME,
}	t_type;

typedef enum e_keys
{
	A_KEY = 0,
	B_KEY,
	C_KEY,
	D_KEY,
	E_KEY,
	F_KEY,
	G_KEY,
	H_KEY,
	I_KEY,
	J_KEY,
	K_KEY,
	L_KEY,
	M_KEY,
	N_KEY,
	O_KEY,
	P_KEY,
	Q_KEY,
	R_KEY,
	S_KEY,
	T_KEY,
	U_KEY,
	V_KEY,
	W_KEY,
	X_KEY,
	Y_KEY,
	Z_KEY,
	SPACE_KEY,
	ARROWLEFT_KEY,
	ARROWUP_KEY,
	ARROWRIGHT_KEY,
	ARROWDOWN_KEY,
}	t_keys;

typedef struct pos_vector
{
	float	x;
	float	y;
	float	w;
	float	h;
}	t_pos_vector;

#endif
