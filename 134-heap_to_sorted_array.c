#include "binary_trees.h"

/**
 * tree_height - Measures the sum of heights of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The sum of height or 0 if tree is NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = 1 + tree_height(tree->left);

	if (tree->right)
		height_right = 1 + tree_height(tree->right);

	return (height_left + height_right);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: A pointer to array sorted in descending order.
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_height(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
