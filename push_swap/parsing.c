#include "libft/libft.h"
#include "push_swap.h"
#include "stack/stack.h"

t_stack	*ft_parse(char **argv, int argc, t_stack *a)
{
	int	i;
	int	split;
	char	**nums;

	split = 0;
	if (argc == 2)
	{
		split = 1;
		nums = ft_split(argv[1], ' ');
	}
	else
		nums = &argv[1];
	i = 0;
	while ((split && nums[i] != NULL) || (!split && i < argc - 1))
	{
		a->a[i] = ft_atoi(nums[i]);
		a->size++;
		i++;
		if (split)
			free(nums[i]);
	}
	if (split)
		free(nums);
	return (a);
}
