#include "../../headers/header.h"

// Changes the "this vector"
// another way of saying it changes the current working vector
t_vector	*vector(t_vector *vector)
{
	fthis()->vector = vector;
	return (vector);
}

// Changes the "this object"
// another way of saying it changes the current working object
t_object	*object(t_object *object)
{
	fthis()->object = object;
	return (object);
}

t_this	*fthis(void)
{
	static t_this	this;

	return (&this);
}
