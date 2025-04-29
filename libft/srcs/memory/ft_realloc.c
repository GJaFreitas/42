#include "../../libft.h"

// Copies from the old ptr and then fills the rest of the memory with 0's
void	*ft_realloc(void *old, size_t prev_size, size_t new_size)
{
	void	*new;

	new = malloc(new_size);
	ft_memcpy(new, old, prev_size);
	ft_bzero(new + prev_size, new_size - prev_size);
	return (new);
}
