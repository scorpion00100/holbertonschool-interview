#ifndef BINARY_H
#define BINARY_H
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/** Binary Search Tree */
typedef struct binary_tree_s bst_t;
/** AVL Tree */
typedef struct binary_tree_s avl_t;
/** Max Binary Heap */
typedef struct binary_tree_s heap_t;

/** Prototypes */
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

int binary_tree_height(const binary_tree_t *tree);
void heapify_up(binary_tree_t *node);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

typedef struct binary_tree_s heap_t;
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);

#endif

