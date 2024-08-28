#ifndef CANVA_H
# define CANVA_H

typedef struct s_canva t_canva;
typedef struct s_sprite t_sprite;

struct s_sprite
{
	void	*img;
	char	*address;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct s_canva
{
	t_sprite	data;
	t_sprite	*(*load_img)(char *texture_name);
};

t_canva		*canva(void);
void		start_screen(void);

#endif
