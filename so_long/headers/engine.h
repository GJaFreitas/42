#ifndef ENGINE_H
# define ENGINE_H

# include "helper_structs.h"

typedef unsigned char byte;

typedef struct s_engine t_engine;

struct s_engine
{
	void			*mlx;
	void			*win;
	int			width;
	int			height;
	t_pos_vector		mouse;
	void			(*destroy)(void);
	int			keys_pressed;
	int			mouse_press;
	byte			keys[75000];
	int			argc;
	char			**argv;
};

t_engine	*engine(void);
void		start_engine(char *title, char **argv, int argc);

#endif
