#include "lib.h"

int	encode_rgb(byte red, byte green, byte blue)
{
	return ( red << 16 | green << 8 | blue);
}


void	colorscreen(t_data data, int color)
{
}
