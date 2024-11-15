#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_dlist t_dlist;

struct s_dlist
{
	int		n;
	t_dlist		*prev;
	t_dlist		*next;
};

#endif
