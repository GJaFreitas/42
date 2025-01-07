#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_dlist t_dlist;
typedef struct s_dlnode t_dlnode;

struct s_dlnode
{
	void			*content;
	t_dlnode		*prev;
	t_dlnode		*next;
};

struct s_dlist
{
	t_dlnode	*head;
	t_dlnode	*tail;
	unsigned int		size;
};

t_dlist		*newList();
t_dlnode	*newNode(void *content);
void		addFront(t_dlnode *node, t_dlist *l);
void		addBack(t_dlnode *node, t_dlist *l);
void		addNext(t_dlist *l, t_dlnode *current, void *content);
t_dlnode	*pop_head(t_dlist *l);
t_dlnode	*pop_tail(t_dlist *l);
t_dlnode	*pop_this(t_dlist *list, t_dlnode *node);
void		destroyNode(t_dlnode *node);

#endif
