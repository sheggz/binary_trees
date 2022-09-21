#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return:  a pointer to the new node, or NULL on failure
 *
 * Description:
 * When created, a node does not have any child
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	/* if parent is NULL then we are going to create the root node */
	/* so that check is not needed */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node != NULL)
	{
		new_node->n = value;
		new_node->parent = parent;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return (new_node);
}
