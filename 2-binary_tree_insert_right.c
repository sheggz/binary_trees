#include <stdlib.h>
#include"binary_trees.h"

/**
 * binary_tree_insert_right -  a function that inserts a node as the
 *				 right-child of another node
 * @parent:  a pointer to the node to insert the right-child in
 * @value:  is the value to store in the new node
 * Return: a pointer to d created node, or NULL on failure or if parent is NULL
 *
 * Description:
 * If parent already has a right-child, the new node must take its place, and
 * the old right-child must be set as the right-child of the new node.
 *
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;
	/* here, parent is not permitted to be NULL */
	if (!parent)
		return (NULL);

	/*
	 * if parent is not Null, store whatever is in the right
	 * of parent to temp
	 */
	temp = parent->right;
	/* create a new node with its parent set to the given parent */
	parent->right = binary_tree_node(parent, value);

	/* if it fails, set i bck 2 its previous value & retrn Null */
	if (!(parent->right))
	{
		parent->right = temp;
		return (NULL);
	}
	/*
	 * if it dsoesnt fail, set right value of the new node to point
	 * to wht thee initial parent's right was (maybe NULL or another node)
	 */
	(parent->right)->right = temp;
	/*
	 * if the right of our new node isnt pointing to NULL, then we set
	 * the parent of the node its pointing to, to point to our new node
	 */
	if (parent->right->right)
		parent->right->right->parent = parent->right;
	return (parent->right);
}
