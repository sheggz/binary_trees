#include "binary_trees.h"

/**
 * binary_tree_leaves -  a function that counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: 0 if tree is NULL
 *
 * Description:
 *
 * if the problem is recursively broken down into the basic model of a
 * parent(root) and two children, we see that we only count "1" when the condi-
 * tion of a leaf is met.therefore on the root node, we dont count(or you can
 * count 0) the total number of leaves in that basic model will be:
 * count_func(left_child/subtree) + count_func(right_child/subtree)
 *
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	else
		return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}
