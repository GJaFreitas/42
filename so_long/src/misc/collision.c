#include "../../headers/header.h"

// TODO: test this i cant rn
// Return 1 when the positions collide and 0 when they dont
int	collides(t_pos_vector pos1, t_pos_vector pos2)
{
	if (((pos1.x > pos2.x && pos1.x < pos2.x + pos2.w)\
	&& (pos1.y > pos2.y && pos1.y < pos2.y + pos2.h))\
	|| ((pos1.x + pos1.w > pos2.x && pos1.x + pos1.w < pos2.x + pos2.w)\
	&& (pos1.y + pos1.h > pos2.y && pos1.y + pos1.h < pos2.y + pos2.h))
	|| ((pos1.x + pos1.w > pos2.x && pos1.x + pos1.w < pos2.x + pos2.w)\
	&& (pos1.y > pos2.y && pos1.y < pos2.y + pos2.h))
	|| ((pos1.x > pos2.x && pos1.x < pos2.x + pos2.w)\
	&& (pos1.y + pos1.h > pos2.y && pos1.y + pos1.h < pos2.y + pos2.h)))
		return (1);
	return (0);
}

// Returns 1 if position is outside boundary of the screen
int	out_of_bounds(t_pos_vector pos)
{
	return ((pos.x > WIDTH || pos.x < 0)
	|| (pos.y > HEIGHT || pos.y < 0));
}

int	collision_check_y(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y + mov][(int)pos.x]\
	&& !game()->walls[(int)(pos.y + mov)][(int)(pos.x + pos.w)]\
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x + pos.w)]\
	&& !game()->walls[(int)(pos.y + pos.h + mov)][(int)(pos.x)]);
}

int	collision_check_x(t_pos_vector pos, int mov)
{
	return (!game()->walls[(int)pos.y][(int)pos.x + mov]\
	&& !game()->walls[(int)(pos.y)][(int)(pos.x + pos.w + mov)]\
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + pos.w + mov)]\
	&& !game()->walls[(int)(pos.y + pos.h)][(int)(pos.x + mov)]);
}
