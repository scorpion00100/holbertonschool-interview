#include "slide_line.h"
#include <stdio.h>

/**
 * merge_left - Merges an array of integers to the left
 *
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 *
 * Return: Nothing
 */
void merge_left(int *line, int size)
{
	int i, tmp, tmp_i;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		else
		{
			if (line[i] == tmp)
			{
				line[i] = 2 * tmp;
				line[tmp_i] = 0;
				tmp = 0;
				tmp_i = 0;
			}
			else
			{
				tmp_i = i;
				tmp = line[i];
			}
		}
	}
}

/**
 * merge_right - Merges an array of integers to the right
 *
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 *
 * Return: Nothing
 */
void merge_right(int *line, int size)
{
	int i, tmp, tmp_i;

	for (i = size - 1; i > -1; i--)
	{
		if (line[i] == 0)
			continue;
		else
		{
			if (line[i] == tmp)
			{
				line[i] = 2 * tmp;
				line[tmp_i] = 0;
				tmp = 0;
				tmp_i = 0;
			}
			else
			{
				tmp_i = i;
				tmp = line[i];
			}
		}
	}
}

/**
 * slide_left - Slides an array of integers to the left
 *
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 *
 * Return: Nothing
 */
void slide_left(int *line, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		else
		{
			j = i;
			while (j != 0 && line[j - 1] == 0)
			{
				line[j - 1] = line[j];
				line[j] = 0;
				j--;
			}
		}
	}
}

/**
 * slide_right - Slides an array of integers to the right
 *
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 *
 * Return: Nothing
 */
void slide_right(int *line, int size)
{
	int i, j;

	for (i = size - 1; i > -1; i--)
	{
		if (line[i] == 0)
			continue;
		else
		{
			j = i;
			while (j != size - 1 && line[j + 1] == 0)
			{
				line[j + 1] = line[j];
				line[j] = 0;
				j++;
			}
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers to the right
 *
 * @line: Points to an array of integers
 * @size: Number of elements in @line
 * @direction: Direction of the slide (left or right)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		merge_left(line, size);
		slide_left(line, size);
	}
	else
	{
		merge_right(line, size);
		slide_right(line, size);
	}
	return (1);
}
