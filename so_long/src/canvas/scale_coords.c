#include "../../headers/header.h"

float	scale_to(int w, int h)
{
	float	scale_factor;

	if (w > h)
		scale_factor = (float)WIDTH / w;
	else
		scale_factor = (float)HEIGHT / h;
	return (scale_factor);
}
