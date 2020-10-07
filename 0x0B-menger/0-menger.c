#include "menger.h"

/**
 * _pow - Pow 3 to n
 * @n: times to pow
 * Return: the power of 3 to n
 */
int _pow(int n)
{
	int pow = 3;

	if (n <= 0)
		return (1);
	while (n > 0)
	{
		pow *= 3;
		n--;
	}
	return (pow);
}
/**
 * print_sponge - Print the sponge
 * @size: size of matrix (size / 3) is every dimension
 * @sponge: sponge to be printed
 * Return: Nothing just print
 */
void print_sponge(int size, char *sponge[size])
{
	int i = 0, j = 0;

	if (size == 1)
	{
		printf("%c\n", sponge[0][0]);
		return;
	}
	for (i = 0; i < size / 3; i++)
	{
		for (j = 0; j < size / 3; j++)
			printf("%c", sponge[i][j]);
		printf("\n");
	}
}
/**
 * add_one - Add a sponge
 * @size: size of matrix (size / 3) is every dimension
 * @sponge: pointer to sponge matrix
 * @x: row in the matrix
 * @y: colum in the matrix
 * @val: value to be inserted
 */
void add_one(int size, char *sponge[size], int x, int y, char val)
{
	int i = x, j = 0;

	while (i < x + 3)
	{
		j = y;
		while (j < y + 3)
		{
			sponge[i][j] = val;
			j++;
		}
		i++;
	}
	sponge[x + 1][y + 1] = ' ';
}
/**
 * update_copy - update the copy of matrix
 * @size: size of matrix (size / 3) is every dimension
 * @org: pointer to original matrix
 * @copy: pointer to copy matrix
 * Return: Nothing
 */
void update_copy(int size, char *org[size], char *copy[size])
{
	int i = 0, j = 0;

	for (i = 0; i < size / 3; i++)
	{
		for (j = 0; j < size / 3; j++)
			copy[i][j] = org[i][j];
	}
}
/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: Nothing
 */
void menger(int level)
{
	int size = _pow(level), i = 0, j = 0, current_level = 1, x = 0, y = 0;
	char **sponge = NULL, **copy = NULL;

	if (size == 1)
	{
		printf("#\n");
		return;
	}
	sponge = malloc(size * sizeof(char *));
	copy = malloc(size * sizeof(char *));
	if (sponge == NULL || copy == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		sponge[i] = malloc(size * sizeof(char *));
		copy[i] = malloc(size * sizeof(char *));
		if (sponge[i] == NULL || copy[i] == NULL)
			return;
	}
	sponge[0][0] = '#', copy[0][0] = '#';
	while (current_level <= level)
	{
		x = 0;
		for (i = 0; (i < size / 3) || (x + 3 <= size / 3); i++)
		{
			y = 0;
			for (j = 0; (j < size / 3) || (y + 3 <= size / 3); j++)
			{
				if (copy[i][j] != ' ')
					add_one(size, sponge, x, y, '#');
				else
					add_one(size, sponge, x, y, ' ');
				y += 3;
			}
			x += 3;
		}
		update_copy(size, sponge, copy);
		current_level++;
	}
	print_sponge(size, sponge);
}
