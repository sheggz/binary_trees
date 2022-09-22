#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node in a binary
 *			tree
 * @tree: a pointer to the node to measure the depth
 * Return: -1 when tree is NULL.
 *
 * Description:
 * with depth, we work from the given node upwards to the root node.
 *
 * if a null (empty) node is considered as an entity, its depth is -1.
 * "BUT!!! WE HAVE BEEN CONSTRAINED TO RETURN 0, WHEN THE FUNNC IS CALLED WITH
 * NULL"
 *
 * if one node is considered as entity existing alone( no children), its depth
 * is 0.
 * while the depth of a child from root is 1.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	/*
	 * should be -1 and should be our base case but because of the
	 * constraint
	 */
	if (!tree)
		return (0);

	/*
	 * this will be our base condition and will prevent the function from
	 * being called recursively on d parent of the root node which is NULL
	 *
	 * BOTH CONDITIONS WERE SPLIT ON PURPOSE, THEY COULD BE JOIND WITH 'or'
	 */

	if (!tree->parent)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
