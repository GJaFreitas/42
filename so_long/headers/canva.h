#ifndef CANVA_H
# define CANVA_H

typedef struct s_canva t_canva;
typedef struct s_sprite t_sprite;

# define COLOR_TRANSPARENT 0xd411aa

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
	unsigned char	(*draw_pixel)(int x, int y, int color);
	void		(*draw_img)(t_sprite *sprite, int x, int y);
};

t_canva		*canva(void);
void		start_screen(void);

#endif