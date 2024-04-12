#include "binary_trees.h"

/**
 * count_leaves - Counts the leaves in a binary tree recursively.
 * @node: A pointer to the current node int the binary tree.
 *
 * Return: The number of leaves in the subtree rooted at @node.
 */
size_t count_leaves(const binary_tree_t *node)
{
	size_t leaves = 0;

	if (node)
	{
		leaves += (!node->left && !node->right) ? 1 : 0;
		leaves += count_leaves(node->left);
		leaves += count_leaves(tree->right);
	}
	return (leaves);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	return count_leaves(tree);
}
