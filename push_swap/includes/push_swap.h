#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../stack/stack.h"
# include <stdlib.h>

typedef short int	t_bool;

typedef struct s_ps
{
	t_stack	*a;
	t_stack	*b;
	t_list	*op_list;
	t_bool	writing;
}	t_ps;

typedef enum e_pos
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B,
}	t_pos;

typedef struct s_chunk
{
	t_pos	pos;
	int		size;
}	t_chunk;

typedef struct s_split_dest
{
	t_chunk	max;
	t_chunk	mid;
	t_chunk	min;
}	t_split_dest;

typedef enum e_op
{
	o_null,
	o_pa,
	o_pb,
	o_ra,
	o_rb,
	o_rr,
	o_rra,
	o_rrb,
	o_rrr,
	o_sa,
	o_sb,
	o_ss
}	t_op;

void		pa(t_ps *data);
void		pb(t_ps *data);

void		sa(t_ps *data);
void		sb(t_ps *data);
void		ss(t_ps *data);

void		ra(t_ps *data);
void		rb(t_ps *data);
void		rr(t_ps *data);

void		rra(t_ps *data);
void		rrb(t_ps *data);
void		rrr(t_ps *data);

/*		Stack		*/

t_stack		*map_stack(const t_stack *s);

/* ------------------------------------ */

/*		Sorting		*/

void		chunk_sort(t_ps *data);
void		ft_sort_three(t_ps *data);

void		sort_three(t_ps *data, t_chunk *to_sort);
void		chunk_split(t_ps *data, t_chunk *to_split, t_split_dest *dest);
void		set_pivots(t_pos pos, int size, int *piv1, int *piv2);
void		set_split_dest(t_pos pos, t_chunk *min, t_chunk *mid, t_chunk *max);
void		sort_one(t_ps *data, t_chunk *to_sort);
void		sort_two(t_ps *data, t_chunk *to_sort);

/* ------------------------------------ */

/*		Post Sort Optimization		*/

void		post_sort_opt(t_ps *data);
t_op		oposite_op(t_op op);
void		remove_op(t_list *delete);
t_op		_mergable(t_op first, t_op second);

/* ------------------------------------ */

/*		Chunk utils		*/

int			chunk_max(t_ps *data, t_chunk *chunk);
int			chunk_min(t_ps *data, t_chunk *chunk);
int			chunk_get(t_ps *data, t_chunk *chunk, int n);
int			move_from_to(t_ps *data, t_pos from, t_pos to);
t_stack		*chunk_locate(t_ps *data, t_pos pos);

/* ------------------------------------ */

/*		Moves		*/

void		save_move(t_ps *data, t_op op);
void		print_op(t_list *current);
t_op		string_to_op(char *str);
const char	*op_to_string(t_op op);

/* ------------------------------------ */
#endif
