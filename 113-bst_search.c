#include "binary_trees.h"

/i**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 *
 * Return: If the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *root, int value)
{
	if (root != NULL)
	{
		if (root->n == value)
			return ((bst_t *)root);
		if (root->n > value)
			return (bst_search(root->left, value));
		return (bst_search(root->right, value));
	}
	return (NULL);
}
