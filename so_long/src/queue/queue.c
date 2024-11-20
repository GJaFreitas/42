#include "../../headers/header.h"

int	adds = 0;
int	pops = 0;
int	destroys = 0;

static void	*__pop_q(t_queue *q)
{
	pops++;
	t_element	*pop;
	void		*ret;

	pop = q->top;
	if (pop)
		q->top = pop->next;
	ret = pop->value;
	free(pop);
	return (ret);
}

static void	__add_q(void *content, t_queue *q)
{
	adds++;
	t_element	*current;

	if (!q->top)
	{
		current = malloc_safe(sizeof(t_element));
		q->top = current;
		current->value = content;
		return ;
	}
	current = q->top;
	while (current && current->next)
		current = current->next;
	current->next = malloc_safe(sizeof(t_element));
	current = current->next;
	current->value = content;
}

// Destructor with an option to destroy the contents stored or not.
static void	__destroy_q(t_queue *q, void (*f)(void *))
{
	t_element	*current;
	t_element	*prev;

	current = q->top;
	while (current)
	{
		prev = current;
		current = current->next;
		if (f)
			f(prev->value);
		free(prev);
		destroys++;
	}
	printf("Adds: %d\n", adds);
	printf("Pops: %d\n", pops);
	printf("Destroys: %d\n", destroys);
	printf("Net total: %d\n", adds - pops - destroys);
	free(q);
}

t_queue	*new_queue(void)
{
	t_queue	*q;

	q = malloc_safe(sizeof(t_queue));
	q->add = __add_q;
	q->pop = __pop_q;
	q->destroy = __destroy_q;
	return (q);
}
