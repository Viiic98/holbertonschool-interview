#include "sandpiles.h"
/**
 * verify_sandpile - Verify if there is value
 *                   inside the grid greater than 4
 * @grid: grid to be evaluated
 * Return: return 1 if there is at least 1
 *         or 0 if there isn't
 */
int verify_sandpile(int grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
	{
			if (grid[i][j] >= 4)
				return (1);
		}
	}
	return (0);
}
/**
 * print_grid - Print a 3 x 3 grid
 * @grid: grid to be printed
 * Return: Nothing, just print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_convert - Sandpile converter
 * This is going to repeat until grid can't be converted
 * @grid: Initial grid to be converted
 * Return: Nothing, just convert and print every time
 */
void sandpiles_convert(int grid[3][3])
{
	int a[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	while (verify_sandpile(grid))
	{
		printf("=\n");
		print_grid(grid);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] < 4)
					a[i][j] = 1;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] >= 4 && a[i][j] == 0)
				{
					if (i - 1 >= 0)
						grid[i - 1][j]++;
					if (i + 1 <= 2)
						grid[i + 1][j]++;
					if (j - 1 >= 0)
						grid[i][j - 1]++;
					if (j + 1 <= 2)
						grid[i][j + 1]++;
					grid[i][j] -= 4;
				}
				a[i][j] = 0;
			}
		}
	}
}
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
	sandpiles_convert(grid1);
}
