#include <stdlib.h>
#include"binary_trees.h"

/**
 *
 *
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;
	/* here, parent is not permitted to be NULL */
	if (!parent)
		return (NULL);
	/* if parent is not Null, check if parent->left already has an adress*/
	
	if (!(parent->left))
	{
		parent->left = binary_tree_node(parent, value);
		if(!parent->left)
			return (parent->left);
	}
	else
	{
	
		temp = parent->left;
		parent->left = binary_tree_node(parent, value);
		if (!parent->left)
		{
			parent->left = temp;
			return (NULL);
		}
		parent->left->left = temp;
	}
	return (parent->left);
}
