#include "../../headers/header.h"

void	harbinger_of_chaos(void)
{
	game()->goodbye = 1;
	canva()->destroy();
	game()->destructor();
	engine()->destroy();
	exit(0);
}
