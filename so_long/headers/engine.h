#ifndef ENGINE_H
# define ENGINE_H

typedef unsigned char byte;

typedef struct s_engine t_engine;

struct s_engine
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	void		(*destroy)(void);
	int		keys_pressed;
	byte		keys[100];
};

t_engine	*engine(void);
void		start_engine(char *title, int w, int h);

#endif