#ifndef LIB_H
# define LIB_H

# include "definitions.h"
# include "../libs/libft/libft.h"
# include "../libs/libft/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>

// Data initialization and destruction
void	img_destructor(t_img *img, void *mlx_ptr);
int	mlx_destructor(t_data data);
t_img	*img_init();
t_data	data_init();

// Rendering functions
void	render(t_data data);
void	color_screen(t_data data, int color);
int	encode_rgb(byte red, byte green, byte blue);
int	encode_trgb(byte opacity, byte red, byte green, byte blue);
void	pixel_put_optimization(t_img img, int x, int y, int color);

// Square.c
void	draw_square(int x, int y, int size, int color, t_data data);
void	walk(int keycode, void *data);
void	start_screen(t_data data);

#endif