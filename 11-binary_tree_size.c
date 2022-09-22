#include "binary_trees.h"

/**
 * binary_tree_size - a function that counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: NULL if tree is 0
 *
 * Description:
 *
 * if the problem is recursively broken down into the basic model of one parent
 * and two children, where the left child is the size of the left subtree and d
 * right child is the size of the right subtree,
 * we see that the total number of nodes in that 3-set is
 * 1(root node size) + left_subtree_size + right_subtree_size
 *
 * the size of a NULL node is 0
 * the size of a leaf node is 1
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
