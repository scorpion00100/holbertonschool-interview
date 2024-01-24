#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
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
 * is_stable - Checks if a 3x3 grid is stable
 * @grid: 3x3 grid
 *
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * is_part_stable - checks if a grain of sand is stable
 * @grid_copy: 3x3 grid
 * @grid: 3x3 grid
 * @i: row index
 * @j: column index
 *
 * Return: 1 if yes, 0 otherwise
 */
int is_part_stable(int grid_copy[3][3], int grid[3][3], int i, int j)
{
	if (grid_copy[i][j] < 4)
	{
		grid[i][j] += 1;
		return (1);
	}
	return (0);
}

/**
 * topple_sandpile - topples a sandpile
 * @grid1: 3x3 grid to topple
 * @grid_copy: 3x3 grid
 * @i: row index
 * @j: column index
 *
 * Return: the number of grains of sand to be removed from grid1[i][j]
 */
int topple_sandpile(int grid1[3][3], int grid_copy[3][3], int i, int j)
{
	int topple = 0;

	if (i - 1 >= 0)
		topple += is_part_stable(grid_copy, grid1, i - 1, j);
	else
		topple += 1;
	if (i + 1 < 3)
		topple += is_part_stable(grid_copy, grid1, i + 1, j);
	else
		topple += 1;
	if (j - 1 >= 0)
		topple += is_part_stable(grid_copy, grid1, i, j - 1);
	else
		topple += 1;
	if (j + 1 < 3)
		topple += is_part_stable(grid_copy, grid1, i, j + 1);
	else
		topple += 1;
	return (topple);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, topple = 0;
	int grid_copy[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid_copy[i][j] = grid1[i][j] + grid2[i][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid_copy[i][j];

	while (is_stable(grid_copy) == 0)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				topple = 0;
				if (grid_copy[i][j] > 3)
				{
					topple = topple_sandpile(grid1, grid_copy, i, j);
					grid1[i][j] -= topple;
				}
			}
		}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid_copy[i][j] = grid1[i][j];
	}
}
