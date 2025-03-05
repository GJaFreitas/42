#include "../../headers/header.h"

void	__vec_normalization(float *x, float *y)
{
	double	module;

	module = sqrt((pow(*x, 2)) + (pow(*y, 2)));
	*x /= module;
	*y /= module;
}
