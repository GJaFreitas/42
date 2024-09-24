#include "../../headers/header.h"

int	rng(int lowerbound, int upperbound)
{
	return ((rand() % (upperbound - lowerbound + 1)) + lowerbound);
}
