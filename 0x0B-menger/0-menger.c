#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: Nothing
 */
void menger(int level)
{
	int size = pow(3, level), i = 0, j = 0, x = 0, y = 0;
	char val = '#';

	if (level < 0)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i, y = j, val = '#';
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					val = ' ';
				x = x / 3;
				y = y / 3;
			}
			printf("%c", val);
		}
		printf("\n");
	}
}
