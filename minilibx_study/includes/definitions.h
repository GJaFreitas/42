#ifndef DEFS_H
#define DEFS_H

// Window Sizes
# define WIDTH 800
# define LENGHT 800


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

typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int	size;
	int			color;
}	t_square;

// Struct for creating images
typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int	h;
	int	w;
	int	bits_per_pixel;
	int	endian;
	int	line_len;
}	t_img;

// Struct with all mlx pointers
typedef struct
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_img	*img;
} 	s_data;
typedef s_data *t_data;

typedef unsigned char	byte;

#endif