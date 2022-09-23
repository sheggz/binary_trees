#include <stddef.h>
#include <stdbool.h>
#include "binary_trees.h"

bool leaf_depth(const binary_tree_t *tree, size_t height);

/**
 * binary_tree_is_perfect -  a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 if NULL or not perfect, 1 if perfect.
 *
 * Description: A binary tree is perfect id all levels in the binary
 * tree are completely filled with nodes. Breaking this down,
 * it means that a binary tree will be perfect if:
 * - it is full
 * - all leaves in the Bst have same depth or wre can say that the depth of
 *   every leaf should be equal to the height of the tree
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t full, height;
	bool compare_depth;

	if (!tree)
		return (0);

	/* check if any node has just 1 child */
	full = binary_tree_is_full(tree);
	if (full == 0)
		return (0);
	/* if the tree is ceertified full, then calculate its height */
	height = binary_tree_height(tree);
	/* compare this height with the depth of all leaf nodes */

	compare_depth = leaf_depth(tree, height);
	if (compare_depth == false)
		return (0);
	else
		return (1);
}
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

/**
 * leaf_depth - a function that checks if all leaves of a tree have same height
 * @tree: the pointer to the rootnode of the tree
 * @height: height of the tree in question
 * Return: true if all nodes have same height as the tree, else false
 */

bool leaf_depth(const binary_tree_t *tree, size_t height)
{
	/*
	 * should be -1 and should be our base case but because of the
	 * constraint
	 */
	if (!tree)
		return (false);

	if (!tree->right && !tree->left)
		return (height == binary_tree_depth(tree));

	if (leaf_depth(tree->left, height) == false ||
		       leaf_depth(tree->right, height) == false)
		return (false);
	else
		return (true);
}

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
