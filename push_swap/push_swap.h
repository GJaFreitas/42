#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stack/stack.h"
# include "dlinked_list/dlinked_list.h"

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *a, t_stack *b);

void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *a, t_stack *b);

#endif
