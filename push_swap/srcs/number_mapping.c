#include "../includes/push_swap.h"

static int	__partition(int arr[], int low, int high)
{
	int	p;
	int	i;
	int	j;
	int	temp;

	p = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= p && i <= high - 1)
			i++;
		while (arr[j] > p && j >= low + 1)
			j--;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return (j);
}

static void	__quicksort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = __partition(arr, low, high);
		__quicksort(arr, low, pi - 1);
		__quicksort(arr, pi + 1, high);
	}
}

// Find in the original stack where the number in the sorted stack is eg:
// origin: [7 1 5 2 9]   sorted: [1 2 5 7 9]
// new: [4 2 3 2 5]
// The seven is in the 4th position and the 1
// is in the first position and so forth
//
// Since the numbers can't repeat sorting the new stack
// will take the same steps as sorting the original stack
// but when viewing the information it will make more
// sense and will be easier to spot mistakes
static void	__populate_indexed(t_stack *new,
const t_stack *temp, const t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
		stack_add(new, 1 + stack_find(temp, s->a[i++]));
}

static int	__check_dup(t_stack *sorted)
{
	int	i;

	i = 0;
	while (i < sorted->size)
	{
		if (sorted->a[i] == sorted->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

t_stack	*map_stack(const t_stack *s)
{
	t_stack	*temp;
	t_stack	*new;

	new = stack_new();
	temp = stack_copy(s);
	__quicksort(temp->a, 0, temp->size - 1);
	if (__check_dup(temp))
		return (ft_printf("Duplicate numbers\n"), NULL);
	__populate_indexed(new, temp, s);
	free(temp);
	return (new);
}
