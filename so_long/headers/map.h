/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:03:35 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 17:03:37 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "canva.h"
# include "helper_structs.h"

typedef unsigned char			t_byte;

typedef struct s_map			t_map;
typedef struct s_object			t_object;
typedef struct s_ff				t_ff;

struct s_ff
{
	t_pos_vector		pos;
	char				*key;
};

struct s_map
{
	t_type				type;
	t_pos_vector		pos;
	double				hp;
	t_sprite			*sprite;

	void				(*render)();
	void				(*update)();
	void				(*destructor)();
	void				(*collision)(t_object*);
	void				(*func_keys)();
	void				(*func_mouse)();
	void				(*set_pos)(t_pos_vector);
	void				(*damage)(double);
	t_sprite			*(*get_sprite)(char);

	char				**map_ptr;
	int					row;
	int					col;
	t_pos_vector		start;
	t_pos_vector		exit;
	t_pos_vector		enemies[128];
	t_pos_vector		collectibles[128];
	unsigned int		collectible_num;
	t_sprite			*enemy_sprite;
	t_sprite			*collectible_sprite;
	// List of errors:
	// Walls are wrong
	// No start, no exit, 2 starts, 2 exits
	// No collectibles
	// Unrecognized char
	// Start not connected to end
	// Not all collectibles are collectible
	t_byte				error[9];
};

t_map	*new_map(char *filepath);

#endif
