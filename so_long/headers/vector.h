/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:48:16 by gjacome-          #+#    #+#             */
/*   Updated: 2025/03/21 16:48:19 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

// My own implementation of C++ vectors
// Basically an array of void* that can manage its own memory
// and do a bunch of other cool stuff

# include "helper_structs.h"

typedef struct s_vector			t_vector;
typedef struct s_element		t_element;

struct s_element
{
	void				*value;
	t_type				type;
	struct s_element	*next;
};

// Destroy -> destroys instance
// Remove all -> destroys all elements in instance
// Remove value -> destroys specific value
// should have named that guy destroy value, what was i thinking
struct s_vector
{
	t_element		*begin;
	t_element		*end;
	int				size;
	t_element		*(*add)(void	*value);
	void			*(*get)(int	index);
	t_element		*(*set_at_index)(int index, void *value);
	void			(*remove_index)(int index);
	void			(*remove_first)();
	void			(*for_each)(void (*fun)(t_element *e, void *v), void *o);
	void			(*for_index)(void (*fun) \
			(t_element *e, void *v), void *o, int index);
	void			(*remove_value)(void *value);
	void			(*remove_all)(void);
	void			(*remove_this)(t_element *e);
	void			(*destroy)();
	void			(*sort)();
};

t_vector	*vector(t_vector *vector);
void		*new_vector(void);

#endif
