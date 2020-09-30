#include "slide_line.h"
/**
 * left - slides and merges an array of integers from left side
 * @line: points to an array of integers containing size elements
 * @size: Size of array
 * @direction: 1 if it's left, 2 if it's right
 * Return: 1 upon success, or 0 upon failure
 */
void left(int *line, size_t size, int direction)
{
	int i = 1, x = 0;

	while (x < size)
	{
		if (line[x] == line[i] && line[i] != 0 && (x != i))
		{
			line[x] += line[i];
			line[i] = 0;
			x++;
		} else if (line[x] != line[i] && line[i] != 0 && line[x] == 0 && (x != i))
		{
			line[x] = line[i];
			line[i] = 0;
		}
		if (i + 1 < size)
			i++;
		else
			x++;
	}
}
/**
 * right - slides and merges an array of integers from right side
 * @line: points to an array of integers containing size elements
 * @size: Size of array
 * @direction: 1 if it's left, 2 if it's right
 * Return: 1 upon success, or 0 upon failure
 */
void right(int *line, size_t size, int direction)
{
	int x = size - 1, i = x - 1;

	while (x >= 0)
	{
		if (line[x] == line[i] && line[i] != 0 && (x != i))
		{
			line[x] += line[i];
			line[i] = 0;
			x--;
		} else if (line[x] != line[i] && line[i] != 0 && line[x] == 0 && (x != i))
		{
			line[x] = line[i];
			line[i] = 0;
		}
		if (i - 1 >= 0)
			i--;
		else
			x--;
	}
}
/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: Size of array
 * @direction: 1 if it's left, 2 if it's right
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == 1)
		left(line, size, direction);
	else if (direction == 2)
		right(line, size, direction);
	else
		return (0);
	return (1);
}
