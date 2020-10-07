#include "menger.h"

void menger(int level)
{
	int size = pow(3, level);

	if (level < 0)
		return;
	if (size == 1)
	{
		printf("#\n");
		return;
	}
	
}
