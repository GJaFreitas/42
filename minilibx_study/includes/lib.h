#ifndef LIB_H
# define LIB_H

# include "definitions.h"
# include "../libs/libft/libft.h"
# include "../libs/libft/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>

// Rendering functions
void	color_screen(t_data data, int color);
int	encode_rgb(byte red, byte green, byte blue);

#endif
