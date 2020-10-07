#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: Nothing
 */
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
