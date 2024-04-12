#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal.
 * @node: A pointer to the current node being visited.
 * @func: A pointer to a function to call for each visited.
 */
void binary_tree_preorder(const binary_tree_t *node, void (*func)(int))
{
	if (node && func)
	{
		func(node->n);
		binary_tree_preorder(node->left, func);
		binary_tree_preorder(node->right, func);
	}
}
