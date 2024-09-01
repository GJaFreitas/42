#include "../../headers/header.h"

#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW 2299*/
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */

// a will be in position 0 of the engine()->keys array
// z will be at 25 of course
// 0 to 9 will be 26 to 35
// space will be 36
// arrow keys from 37 to 40
// Escape will be 99
static int	__key(int key)
{
	if (key >= XK_a && key <= XK_z)
		return (key - 97);
	if (key >= XK_0 && key <= XK_9)
		return (key - 23);
	if (key >= XK_leftarrow && key <= XK_downarrow)
		return (key - 2192);
	if (key == XK_KP_Space)
		return (36);
	if (key == XK_Escape)
		return (99);
	return (98);
}

int	__key_press(int key, void *engine)
{
	if (key == XK_Escape)
		harbinger_of_chaos();
	if (!((t_engine*)engine)->keys[__key(key)])
		((t_engine*)engine)->keys_pressed++;
	((t_engine*)engine)->keys[__key(key)] = 1;
	return (0);
}

int	__key_release(int key, void *engine)
{	
	if (((t_engine*)engine)->keys[__key(key)])
		((t_engine*)engine)->keys_pressed--;
	((t_engine*)engine)->keys[__key(key)] = 0;
	return (0);
}
