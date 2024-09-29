#include "../../headers/header.h"

void	__vec_normalization(float *x, float *y)
{
	double	module;

	module = sqrt((*x * *x) + (*y * *y));
	*x /= module;
	*y /= module;
}
