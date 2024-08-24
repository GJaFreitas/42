#ifndef LIB_H
# define LIB_H

// Window Sizes
# define WIDTH 600
# define LENGHT 400


// X11 Masks
# define KPRESS_M 1
# define KRELEASE_M 2
# define BPRESS_M 4
# define BRELEASE_M 8


// Event Hook Codes
# define ON_KEYDOWN	2
# define ON_KEYUP	3
# define ON_MOUSEDOWN	4
# define ON_KEYMOUSEUP	5
# define ON_MOUSEMOVE	6


# include "libs/libft/libft.h"
# include "libs/libft/ft_printf.h"
# include "libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>

// Struct with all mlx pointers
typedef struct
{
	void	*mlx_ptr;
	void	*mlx_window;
} 	s_data;
typedef s_data *t_data;

typedef unsigned char	byte;

#endif
