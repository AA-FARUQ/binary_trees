#include "binary_trees.h"

size_t get_height(const binary_tree_t *tree);
int calculate_balance(const binary_tree_t *tree);
avl_t *insert_recursive_avl(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * get_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t get_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 get_height(tree->left) : 1;
		right_height = tree->right ? 1 + get_height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * calculate_balance - Calculates the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to calculate the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int calculate_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? get_height(tree->left) - get_height(tree->right) : 0);
}

/**
 * insert_recursive_avl - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *insert_recursive_avl(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = insert_recursive_avl(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insert_recursive_avl(&(*tree)->right
				, *tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance_factor = calculate_balance(*tree);
	if (balance_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert_recursive_avl(tree, *tree, &new_node, value);
	return (new_node);
}
