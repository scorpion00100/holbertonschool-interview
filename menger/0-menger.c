#include "menger.h"

/**
 * check_char - Checks space for block.
 * @column: The column.
 * @row: The row.
 *
 * Return: # or space.
 */
char check_char(int column, int row)
{
	while (column > 0 || row > 0)
	{
		if (column % 3 == 1 && row % 3 == 1)
			return (' ');
		column /= 3;
		row /= 3;
	}
	return ('#');
}

/**
 * menger - Function that draws a 2D Menger Sponge.
 * @level: The level of the Menger Sponge to draw.
 *
 * Return: Void.
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;

	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%c", check_char(i, j));
		printf("\n");
	}
}
