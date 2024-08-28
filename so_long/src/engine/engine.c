#include "../../headers/header.h"

int	__key_press(int key, void *v);
int	__key_release(int key, void *v);

static void	__destroy_all(void)
{
	mlx_destroy_window(engine()->mlx, engine()->win);
	mlx_destroy_display(engine()->mlx);
	free(engine()->mlx);
}

t_engine	*engine(void)
{
	static t_engine	engine;

	return (&engine);
}

t_engine	*start_engine(char *title, int w, int h)
{
	engine()->height = h;
	engine()->width = w;
	engine()->mlx = mlx_init();
	engine()->win = mlx_new_window(engine()->mlx, w, h, title);
	engine()->destroy = __destroy_all;
	mlx_hook(engine()->mlx, ON_KEYDOWN, KPRESS_M, __key_press, NULL);
	mlx_hook(engine()->mlx, ON_KEYUP, KRELEASE_M, __key_release, NULL);
	return (engine());
}
