#include "binary_trees.h"

/**
 * swap - Swaps two values using the Heap sort algorithm
 *
 * @a: First value
 * @b: Second value
 */
void swap(heap_t *a, heap_t *b)
{
	int tmp = b->n;

	b->n = a->n;
	a->n = tmp;
}

/**
 * heapify - Builds a heap from the element to be sorted
 *
 * @root: double pointer to the root node
 */
void heapify(heap_t **root)
{
	heap_t *max = *root;
	heap_t *left = (*root)->left;
	heap_t *right = (*root)->right;

	if (left && left->n > max->n)
		max = left;
	if (right && right->n > max->n)
		max = right;

	if (max != *root)
	{
		swap(*root, max);
		heapify(&max);
	}
}

/**
 * heap_size - Gets the size of the heap
 *
 * @root: pointer to the root node of the heap
 * Return: the size of the heap
 */
int heap_size(heap_t *root)
{
	if (!root)
		return (0);

	return (heap_size(root->left) + 1 + heap_size(root->right));
}

/**
 * get_last_node - Gets the last level-order node of the heap
 *
 * @root: pointer to the root node of the heap
 * @size: size of the heap
 * Return: the last level-order node of the heap
 */
heap_t *get_last_node(heap_t *root, int size)
{
	heap_t **queue = malloc(size * sizeof(heap_t *));
	heap_t *node = NULL;
	int level = 0, index;

	if (!root || size == 0 || !queue)
		return (NULL);

	queue[level++] = root;
	index = 0;

	while (index < size)
	{
		node = queue[index++];
		if (node->left)
			queue[level++] = node->left;
		if (node->right)
			queue[level++] = node->right;
	}
	free(queue);

	return (node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: double pointer to the root node of the heap
 * Return: the value stored in the root node on success, 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value, size;
	heap_t *last_node;

	if (!root || !(*root))
		return (0);

	value = (*root)->n;
	size = heap_size(*root);
	last_node = get_last_node(*root, size);
	if (!last_node)
		return (0);

	/* Disconnect last node from its parent */
	if (last_node->parent && last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else if (last_node->parent && last_node->parent->right == last_node)
		last_node->parent->right = NULL;

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Move last node to the root and re-balance the heap */
	last_node->left = (*root)->left;
	last_node->right = (*root)->right;
	last_node->parent = NULL;

	if (last_node->left)
		last_node->left->parent = last_node;
	if (last_node->right)
		last_node->right->parent = last_node;

	free(*root);
	*root = last_node;

	heapify(root);

	return (value);
}

