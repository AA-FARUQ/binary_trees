#include "binary_trees.h"

/**
 * count_leaves - Counts the leaves in a binary tree recursively.
 * @tree: A pointer to the current node int the binary tree.
 *
 * Return: The number of leaves in the subtree rooted at @node.
 */
size_t count_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += count_leaves(tree->left);
		leaves += count_leaves(tree->right);
	}
	return (leaves);
}
