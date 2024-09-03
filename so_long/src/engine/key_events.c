#include "../../headers/header.h"

int	__key_press(int key, void *engine)
{
	if (key == XK_Escape)
		harbinger_of_chaos();
	if (!((t_engine*)engine)->keys[key])
		((t_engine*)engine)->keys_pressed++;
	((t_engine*)engine)->keys[key] = 1;
	return (0);
}

int	__key_release(int key, void *engine)
{	
	if (((t_engine*)engine)->keys[key])
		((t_engine*)engine)->keys_pressed--;
	((t_engine*)engine)->keys[key] = 0;
	return (0);
}
