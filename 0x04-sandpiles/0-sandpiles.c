#include "sandpiles.h"
/**
 * sandpiles_sum - Sum two grids and then convert
 * the result grid to sandpile
 * @grid1: Grid number one
 * @grid2: Grid number two
 * Return: Nothing, just sum
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
}
