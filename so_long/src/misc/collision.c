#include "../../headers/header.h"

int	collides(t_pos_vector pos1, t_pos_vector pos2)
{
	if ((pos1.x > pos2.x && pos1.x < pos2.x + pos2.w)\
	&& (pos1.y > pos2.y && pos1.y < pos2.y + pos2.h)\
	&& (pos1.x + pos1.w > pos2.x && pos1.x < pos2.x + pos2.w)\
	&& (pos1.y + pos1.h > pos2.y && pos1.y < pos2.y + pos2.h))
		return (1);
	return (0);
}
