#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node1,
		const binary_tree_t *node2)
{
	binary_tree_t *ancestor1, *ancestor2;

	if (!node1 || !node2)
		return (NULL);
	if (node1 == node2)
		return ((binary_tree_t *)node1);

	ancestor1 = node1->parent, ancestor2 = node2->parent;
	if (node1 == ancestor2 || !ancestor1 || (!ancestor1->parent && ancestor2))
		return (binary_trees_ancestor(node1, ancestor2));
	else if (ancestor1 == node2 || !ancestor2 || (!ancestor2->parent && ancestor1))
		return (binary_trees_ancestor(ancestor1, node2));
	return (binary_trees_ancestor(ancestor1, ancestor2));
}
