#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *                     in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: If node is NULL or has no parent or has no grandparent, return NULL.
 *         Otherwise, return a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if node, parent, and grandparent are NULL */
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	/* If node's parent is left child of its grandparent, return right child */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	
	/* If node's parent is right child of its grandparent, return left child */
	return (node->parent->parent->left);
}
