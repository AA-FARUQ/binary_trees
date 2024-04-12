#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @node: A pointer to the current node being visited.
 * @func: A pointer to a function to call for each visited node.
 */
void binary_tree_postorder(const binary_tree_t *node, void (*func)(int))
{
	if (node && func)
	{
		binary_tree_postorder(node->left, func);
		binary_tree_postorder(node->right, func);
		func(node->n);
	}
}
