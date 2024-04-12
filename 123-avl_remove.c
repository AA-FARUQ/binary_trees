#include "binary_trees.h"

/**
 * balance - Measures balance factor of a AVL tree.
 * @tree: Pointer to the AVL tree node to go measure the
 * 	balance factor.
 * 
 * Description: Checks and performs rotations if AVL tree is unbalanced.
 * Return: balanced factor
 */
void balance(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance(&(*tree)->left);
	balance(&(*tree)->right);
	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * get_successor - Finds the successor node in a binary search tree.
 * @node: The node to find the successor for.
 *
 * Return: The value of the minimum in the right subtree.
 */
int get_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = get_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - Removes a node from a binary search tree based on its children.
 *@root: The node to remove
 *Return: 0 if it has no children, or the value of the successor if it has.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = get_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - Remove a node from a binary search tree.
 * @root: The root of the binary search tree.
 * @value: The value to remove from the tree.
 *
 * Return: Pointer to the root node after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value to remove from the tree.
 *
 * Return: Pointer to the root node after removal
 **/
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balance(&root_a);
	return (root_a);
}
