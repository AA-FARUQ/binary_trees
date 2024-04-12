#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @par: A pointer to the parent of the node to create.
 * @val: The value to put in the new node.
 *
 * Return: If memory allocation fails - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *par, int val)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = val;
	new_node->parent = par;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new);
}
