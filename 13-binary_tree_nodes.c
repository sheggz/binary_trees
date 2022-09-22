#include "binary_trees.h"

/**
 * binary_tree_nodes -  a function that counts the nodes with at least 1
 *			child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: 0 if tree is NULL
 *
 * Description:
 *
 * we are basically to count how many nodes are not leaves. therefore, we count
 * leaves as 0 and non leaves as 1
 * if the problem is recursively broken down into the basic model of a
 * parent(root) and two children, we see that we only count "1" when the condi-
 * tion of a non-leaf is met.therefore on the root node, we count 1(because the
 * root node will always meet that criteria). therfore for d basic model it is
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	else
		return (1 + binary_tree_nodes(tree->right) + binary_tree_nodes(tree->left));
}
