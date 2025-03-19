/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2025/03/19 18:21:25 by gjacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Stack
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

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

typedef struct s_dlist
{
	t_op				op;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct s_data
{
	t_list				**stack_a;
	t_list				**stack_b;
	t_dlist				*op_list;
}				t_ps;

// Util functions
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);

t_dlist	*ft_new_dlist(t_op op);
void	ft_addback_dlist(t_dlist **head, t_dlist *new);
void	ft_remove_this(t_dlist *delete);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_list **stack);
int		get_distance(t_list **stack, int index);
void	make_top(t_ps *data, t_list **stack, int distance);
void	free_stack(t_list **stack);
void	free_doubly(t_dlist *list);
void	ft_free(char **str);

// Algorithm utils
void	radix_sort(t_ps *data);
void	simple_sort(t_ps *data);
void	index_stack(t_list **stack);
void	sort_5(t_ps *data);
void	sort_4(t_ps *data);
void	sort_3(t_ps *data);

// Instruction functions
int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverseRotate(t_list **stack);

// Optimizations
void	save_move(char *op, t_ps *data);
void	print_ops(t_ps *data);
t_op	child_op(t_op first, t_op second);
t_op	_mergable(t_op first, t_op second);
t_op	oposite_op(t_op op);
void	post_sort_opt(t_ps *data);

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

#endif
