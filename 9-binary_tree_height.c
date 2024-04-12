#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @node: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *node)
{
	if (node)
	{
		size_t left_height = 0, right_height = 0;

		left_height = node->left ? 1 + binary_tree_height(node->left) : 0;
		right_height = node->right ? 1 + binary_tree_height(node->right) : 0;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}
