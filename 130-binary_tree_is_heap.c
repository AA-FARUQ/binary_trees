#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - Checks if all nodes in a binary tree have valueless than their parent.
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if all nodes are less than their parent, 0 otherwise.
 **/
int check_max(const binary_tree_t *tree)
{
	int left_check = 1, right_check = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		left_check = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		right_check = check_max(tree->right);
	}
	return (left_check && right_check);
}
/**
 * binary_tree_is_heap - Checks if a binary tree is max heap.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete;

	if (!tree)
		return (0);

	is_complete = binary_tree_is_complete(tree);
	if (!is_complete)
		return (0);
	return (check_max(tree));
}
