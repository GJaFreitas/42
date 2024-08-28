#include "../../headers/header.h"

// Returns 0 if v was NULL and 1 if v was sucessfully freed
int	free_safe(void *v)
{
	if (!v)
		return (0);
	free(v);
	return (1);
}


// Checks both if size is > 0 and the malloc return
// if malloc gives NULL then exits the program
void	*malloc_safe(size_t __size)
{
	void	*v;

	// TODO: change exit function to destroy all allocated memory?
	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		exit(-1);
	ft_bzero(v, __size);
	return (v);
}
