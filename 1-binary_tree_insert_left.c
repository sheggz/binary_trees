#include <stdlib.h>
#include"binary_trees.h"

/**
 * binary_tree_insert_left -  a function that inserts a node as the
 *				 left-child of another node
 * @parent:  a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 * Return: a pointer to d created node, or NULL on failure or if parent is NULL
 *
 * Description:
 * If parent already has a left-child, the new node must take its place, and
 * the old left-child must be set as the left-child of the new node.
 *
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;
	/* here, parent is not permitted to be NULL */
	if (!parent)
		return (NULL);

	/*
	 * if parent is not Null, store whatever is in the left
	 * of parent to temp
	 */
	temp = parent->left;
	/* create a new node with its parent set to the given parent */
	parent->left = binary_tree_node(parent, value);

	/* if it fails, set i bck 2 its previous value & retrn Null */
	if (!(parent->left))
	{
		parent->left = temp;
		return (NULL);
	}
	/*
	 * if it dsoesnt fail, set left value of the new node to point
	 * to wht thee initial parent's left was (maybe NULL or another node)
	 */
	(parent->left)->left = temp;
	/*
	 * if the left of our new node isnt pointing to NULL, then we set
	 * the parent of the node its pointing to, to point to our new node
	 */
	if (parent->left->left)
		parent->left->left->parent = parent->left;
	return (parent->left);
}
