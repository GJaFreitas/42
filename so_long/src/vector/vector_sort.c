#include "../../headers/header.h"

// Returns 0 if a comes after b
static int	__compare_obj(void *a, void *b)
{
	return ((((t_object *)a)->type < ((t_object *)b)->type));
}

static void FrontBackSplit(t_element *source,
                    t_element **frontRef,
                    t_element **backRef)
{
	t_element	*fast;
	t_element	*slow;

	slow = source;
	fast = source->next;
	/* Advance 'fast' two nodes, and advance 'slow' one node
     */
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	/* 'slow' is before the midpoint in the list, so split
    it in two at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

static t_element	*__sortedMerge(int (*compare)(void *a, void *b), t_element *a, t_element *b)
{
	t_element* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	/* Pick either a or b, and recur */
	if ((*compare)(a->value, b->value))
	{
		result = a;
		result->next = __sortedMerge(compare, a->next, b);
	}
	else
	{
		result = b;
		result->next = __sortedMerge(compare, a, b->next);
	}
	return (result);
}

static void	__vec_mergesort(t_element** headRef, int (*compare)(void *a, void *b))
{
	t_element	*head;
	t_element	*a;
	t_element	*b;

	head = *headRef;
	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL))
		return;
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);
	/* Recursively sort the sublists */
	__vec_mergesort(&a, compare);
	__vec_mergesort(&b, compare);
	/* answer = merge the two sorted lists together */
	*headRef = __sortedMerge(compare, a, b);
}

void	__vec_sort(void)
{
	return ;
	__vec_mergesort(&fthis()->vector->begin, __compare_obj);
}
