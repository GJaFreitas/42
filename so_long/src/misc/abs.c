#include "../../headers/header.h"

float	f_abs(float val)
{
	if (val < 0)
		return (-val);
	return (val);
}

double	d_abs(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}

int	i_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}