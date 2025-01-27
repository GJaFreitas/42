#include "push_swap.h"

t_dlist	*exec_instruction(char *str)
{
	static t_dlist	list;

	if (str)
		addBack(newNode(str), &list);
	return (&list);
}

int	m_count(char *str)
{
	static int	count;

	if (str != NULL)
	{
		exec_instruction(str);
		count++;
	}
	return (count);
}

void	get_stats(void)
{
	printf("Total moves: %d\n", m_count(NULL));
}
