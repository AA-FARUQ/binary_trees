#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} linked_list;

linked_list *append(linked_list *head, const binary_tree_t *btnode);
void free_list(linked_list *head);
linked_list *get_children(linked_list *head, const binary_tree_t *parent);
void traverse_levels(linked_list *head, void (*func)(int));

/**
 * binary_tree_levelorder - Goes through a binary tree
 *                          using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	linked_list *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	traverse_levels(children, func);

	free_list(children);
}

/**
 * traverse_levels - Calls func on all nodes at each level.
 * @head: Pointer to head of linked list with nodes at one level.
 * @func: Pointer to a function to call for each node.
 */
void traverse_levels(linked_list *head, void (*func)(int))
{
	linked_list *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	traverse_levels(children, func);
	free_list(children);
}

/**
 * get_children - appends children of parent to linked list.
 * @head: Pointer to head of linked list where children will be appended.
 * @parent: Pointer to node whose children we want to append.
 * Return: Pointer to head of linked list of children.
 */
linked_list *get_children(linked_list *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - adds a new node at the end of a linked list
 * @head: pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, or NULL on failure
 */
linked_list *append(linked_list *head, const binary_tree_t *btnode)
{
	linked_list *new_node = NULL, *last = NULL;

	new_node = malloc(sizeof(*new_node));
	if (new_node)
	{
		new_node->node = btnode;
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new_node;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @head: pointer to the head of list_t linked list
 */
void free_list(linked_list *head)
{
	linked_list *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
