#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary tree is full recursively.
 * @node: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is not full, return 0.
 *         Otherwise, return 1.
 */
int is_full_recursive(const binary_tree_t *node)
{
	if (node != NULL)
	{
		if ((node->left != NULL && node->right == NULL) ||
		    (node->left == NULL && node->right != NULL) ||
		    is_full_recursive(node->left) == 0 ||
		    is_full_recursive(node->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not full, return 0.
 *         Otherwis, return 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
