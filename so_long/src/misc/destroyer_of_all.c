#include "../../headers/header.h"

void	harbinger_of_chaos(void)
{
	canva()->destroy();
	game()->destructor();
	engine()->destroy();
	exit(0);
}
