/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:55:23 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/22 11:20:28 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

// Gameplay stuff
# ifndef PLAYER_SPEED
#  define PLAYER_SPEED 15
# endif
# ifndef FIREBALL_SPEED
#  define FIREBALL_SPEED 30
# endif
# ifndef FIREBALL_COOLDOWN
#  define FIREBALL_COOLDOWN 1
# endif

// Window Sizes
// they are purposely mispelt because im mad that
// "user defined identifiers should be only lowercase"
// why? what is the purpose of that? every library ever
// has all their defined constants be uppercase
// retarded norminette doesnt like it tho and now i have
// to change every single one of these defines across
// all these files
# define WIDTH_W 1920
# define HEIGHT_W 1080

// X11 Masks
# define KPRESS_M 		1
# define KRELEASE_M 		2
# define BPRESS_M 		4
# define BRELEASE_M 		8
# define STRUCT_NOTI_MASK	131072

// Event Hook Codes
# define ON_KEYDOWN	2
# define ON_KEYUP	3
# define ON_MOUSEDOWN	4
# define ON_KEYMOUSEUP	5
# define ON_MOUSEMOVE	6
# define DESTROYNOTIFY	17

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <time.h>

# include "objects.h"
# include "engine.h"
# include "vector.h"
# include "canva.h"
# include "this.h"
# include "map.h"

//	Memory manipulation
void				*malloc_safe(size_t __size);
int					free_safe(void **v);
void				harbinger_of_chaos(void);
//	*******************

//	Misc
void				fadeout(void);
int					game_loop(void);
int					collides(t_pos_vector pos1, t_pos_vector pos2);
int					collision_check_y(t_pos_vector pos, int mov);
int					collision_check_x(t_pos_vector pos, int mov);
int					rng(int lowerbound, int upperbound);
int					out_of_bounds(t_pos_vector pos);
void				count_overall(t_type type);
int					count_obj(t_type type);
void				game_over(void);
int					close_game(void *ptr);
//	******************

//	Math
void				__vec_normalization(float *x, float *y);
float				f_abs(float val);
double				d_abs(double val);
int					i_abs(int val);
//	******************

#endif
