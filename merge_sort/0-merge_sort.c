#include "sort.h"

/**
 * top_down_merge - merge the resulting runs from array B[] into A[]
 * @A: array to copy
 * @iBegin: starting index
 * @iMiddle: middle index
 * @iEnd: ending index
 * @B: work array
*/
void top_down_merge(int *B, size_t iBegin, size_t iMiddle, size_t iEnd, int *A)
{
	/*  Left source half is A[iBegin:iMiddle-1]. */
	/* Right source half is A[iMiddle:iEnd-1]. */
	/* Result is            B[iBegin:iEnd-1]. */
	size_t i = iBegin, j = iMiddle, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&A[iBegin], iMiddle - iBegin);
	printf("[right]: ");
	print_array(&A[iMiddle], iEnd - iMiddle);

	/* While there are elements in the left or right runs... */
	for (k = iBegin; k < iEnd; k++)
	{
		/* If left run head exists and is <= existing right run head. */
		if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else
		{
			B[k] = A[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(&B[iBegin], iEnd - iBegin);
}

/**
 * top_down_split_merge - Split A[] into 2 runs,
 * sort both runs into B[],
 * merge both runs from B[] to A[]
 * @A: array to copy
 * @iBegin: starting index
 * @iEnd: ending index
 * @B: work array
 * iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set)
*/
void top_down_split_merge(int *B, size_t iBegin, size_t iEnd, int *A)
{
	size_t iMiddle;

	if (iEnd - iBegin <= 1) /* if run size == 1 */
		return;				/*   consider it sorted */
	/* split the run longer than 1 item into halves */
	iMiddle = (iEnd + iBegin) / 2; /* iMiddle = mid point */
	/* recursively sort both runs from array A[] into B[] */
	top_down_split_merge(A, iBegin, iMiddle, B); /* sort the left  run */
	top_down_split_merge(A, iMiddle, iEnd, B);	  /* sort the right run */
	/* merge the resulting runs from array B[] into A[] */
	top_down_merge(B, iBegin, iMiddle, iEnd, A);
}

/**
 * copy_array - copy into the elements of A into work array B
 * @A: array to copy
 * @iBegin: starting index
 * @n: n elements
 * @B: work array
*/
void copy_array(int *A, size_t iBegin, size_t n, int *B)
{
	size_t k;

	for (k = iBegin; k < n; k++)
		B[k] = A[k];
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm:
 * must implement the top-down merge sort algorithm
 * When you divide an array into two sub-arrays,
 * the size of the left array should always be <= the size of the right array.
 * i.e. {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}
 * Sort the left array before the right array
 * Array A[] has the items to sort
 * @A: array to sort
 * @n: n elements of A
*/
void merge_sort(int *A, size_t n)
{
	int *B = malloc(sizeof(int) * n);  /* array B is a work array. */

	if (!B)
		return;

	copy_array(A, 0, n, B);		   /* one time copy of A[] to B[] */
	top_down_split_merge(A, 0, n, B); /* sort data from B[] into A[] */
	free(B);
}

