#include "binary_trees.h"

/**
 * binary_tree_height -  a function that measures the height of a binary tree
 * @tree:  a pointer to the root node of the tree to measure the height.
 * Return: -1 if tree is NULL (empty tree)
 *
 * Description:
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_subtree, right_subtree,  root_node = 1;

	if (!tree)
		return (-1); /* height of an empty tree is -1 */

	/* recursively calculate the height of left subtree */
	left_subtree = binary_tree_height(tree->left);
	/* recursively calculate the height of right subtree */
	right_subtree = binary_tree_height(tree->right);

	/* return the max of both the left and right subtree */
	if (left_subtree >= right_subtree)
		return (left_subtree + root_node);
	else
		return (right_subtree + root_node);
}
