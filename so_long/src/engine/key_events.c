#include "../../headers/header.h"

void	input_handler(byte *keys, byte event);
// a will be in position 0 of the engine()->keys array
// z will be at 25 of course
// 0 to 9 will be 26 to 35
// space will be 36
// Escape will be 99
static int	__key(int key)
{
	if (key >= XK_a && key <= XK_z)
		return (key - 97);
	if (key >= XK_0 && key <= XK_9)
		return (key - 23);
	if (key == XK_KP_Space)
		return (36);
	if (key == XK_Escape)
		return (99);
	return (98);
}

int	__key_press(int key, void *v)
{
	(void)v;
	if (key == XK_Escape)
		exit(0);
	/*
	engine()->keys[__key(key)] = 1;
	engine()->keys_pressed++;
	input_handler(engine()->keys, ON_KEYDOWN);
	*/
	return (0);
}

int	__key_release(int key, void *v)
{	
	(void)v;
	engine()->keys[__key(key)] = 0;
	engine()->keys_pressed--;
	input_handler(engine()->keys, ON_KEYDOWN);
	return (0);
}

void	input_handler(byte *keys, byte event)
{
	(void)keys;
	(void)event;
}
