#include "sort.h"

/**
 * max_array - Function that get the max size of an array
 * @array: The array
 * @size: The size of the array
 * Return: Nothing
 */
int max_array(int *array, size_t size)
{
    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++)
        if (max < array[i])
            max = array[i];

    return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the counting sort algorithm, according
 * to the digit represented by @exp.
 *
 * @array: The array
 * @size: The size of the array
 * @exp: The significant digit
 * Return: Nothing
 */
void counting_sort(int *array, int size, int exp)
{
    int *output, *count;
    int i;

    output = malloc(size * sizeof(int));
    if (!output)
        return;

    count = malloc(10 * sizeof(int));
    if (!count)
    {
        free(output);
        return;
    }

    for (i = 0; i < 10; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the Radix sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (!array || size < 2)
        return;

    max = max_array(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}
