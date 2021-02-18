#include "sort.h"
/**
 * merge - merge sub arrays [l...m] [m+1...r]
 * @array: array to be merged
 * @l: left
 * @m: mid
 * @r: right
 * Return: Anything
 */
void merge(int *array, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[10000], R[10000];

	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}
/**
 * sort - merge sort algorithm
 * @array: array to be sorted
 * @l: left
 * @r: right
 * Return: Anything
 */
void sort(int *array, int l, int r)
{
	int m = l + (r - l) / 2;

	if (l < r)
	{
		sort(array, l, m);
		sort(array, m + 1, r);
		merge(array, l, m, r);
	}
}
/**
 * merge_sort - merge sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: Anything
 */
void merge_sort(int *array, size_t size)
{
	sort(array, 0, size - 1);
}
