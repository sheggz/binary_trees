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
 * if one node is considered as entity existing alone( no children), its depth
 * is 0.
 * while the depth of a child from root is 1.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		/* -1 for a null(non existentt/empty node */
		return (-1);
	return (1 + binary_tree_depth(tree->parent));
}
