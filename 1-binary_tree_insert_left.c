#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child
 *                           of another in a binary tree.
 * @par: A pointer to the node to insert the left-child in.
 * @val: The value to assign to the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *par, int val)
{
	binary_tree_t *new_node;

	if (par == NULL)
		return (NULL);

	new_node = binary_tree_node(par, val);
	if (new_node == NULL)
		return (NULL);

	if (par->left != NULL)
	{
		new_node->left = par->left;
		par->left->parent = new_node;
	}
	par->left = new_node;

	return (new_node);
}
