#include "../includes/lib.h"

// This is just a template

typedef struct obj obj;

struct obj
{
	int	value;
	void	(*set)(obj*, int);
	int	(*get)(obj*);
};

void	setter(obj* obj, int value)
{
	obj->value = value;
}

int	getter(obj* obj)
{
	return (obj->value);
}

void	contructor(obj* obj)
{
	obj->set = setter;
	obj->get = getter;
}
