#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - a function that deletes an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 *
 * Description:
 * If tree is NULL, do nothing
 */

void binary_tree_delete(binary_tree_t *tree)
{
	/*
	 * RECURSION!!
	 * the parent itself must be deleted last, else we lose access to the
	 * left and right children
	 */
	if (tree)
	{
		if (tree->left) /*
				 * this check is redundant because "if (tree)"
				 * can figure out if the node upon which
				 * binary_tree_delete is called is NULL or not
				 */
			binary_tree_delete(tree->left);
		if (tree->right) /* redundant too */
			binary_tree_delete(tree->right);
		free(tree);
		return;
	}
	else
		return;
}
