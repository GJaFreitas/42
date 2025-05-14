#include "../../libft.h"

// Frees a double pointer array, the size argument is optional
// if the array is NULL terminated;
// The function passed in should be made to free the contents
// of the array
void	free_ptr_array(void **arr, size_t size, void (*f)(void *))
{
	size_t	i;

	i = 0;
	if (size)
		while (i < size)
			f(arr[i++]);
	else
		while (arr[i] != NULL)
			f(arr[i++]);
	free(arr);
}
