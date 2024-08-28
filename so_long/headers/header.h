#ifndef HEADER_H

# define HEADER_H

// Window Sizes
# define WIDTH 1920
# define HEIGHT 1080


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


# include "../libs/libft/libft.h"
# include "../libs/libft/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>


# include "objects.h"
# include "engine.h"
# include "vector.h"
# include "canva.h"
# include "this.h"

//	Memory manipulation
void		*malloc_safe(size_t __size);
int		free_safe(void *v);
void		harbinger_of_chaos(void);
//	*******************

#endif
