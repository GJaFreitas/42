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

t_stack	*ft_parse(char **argv, int argc, t_stack *a);
void	ft_algo(t_stack *a, t_stack *b);
void	ft_show_stack(const t_stack a, const t_stack b);

// Optimization
t_dlist	*exec_instruction(char *str);
void	exec(t_stack *a, t_stack *b, t_dlist *list);
t_dlist	*optimize_instructions(t_dlist *list);
int	m_count(char *str);

#endif
