#include "../../headers/header.h"

t_this	*fthis(void)
{
	static t_this	this;

	return (&this);
}
