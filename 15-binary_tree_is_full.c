#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that checks if a binary tree is perfect
 * @tree:  a pointer to the root node of the tree to check
 * Return: 0 if the tree is NULL or not full and 1 if it is full
 *
 * Description:
 * A full tree is one in whick all nodes have either 0 or two children
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/* check if either child is NULL */
	if ((!tree->left && tree->right) || (!tree->right && tree->left))
		return (0);
	/* check if it is a leaf */
	else if (!tree->left && !tree->right)
		return (1);
	/*
	 * recursively call the function on both sub trees,
	 * checking if anynode returns with only one child
	 */
	if (binary_tree_is_full(tree->left) == 0 ||
			binary_tree_is_full(tree->right) == 0)
		return (0);

	else
		return (1);
}
