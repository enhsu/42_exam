/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:29:23 by exam              #+#    #+#             */
/*   Updated: 2019/03/26 10:44:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	get_tree_size(struct s_node *n)
{
	if (n->left && n->right)
		return (1 + get_tree_size(n->left) + get_tree_size(n->right));
	else if (n->left)
		return (1 + get_tree_size(n->left));
	else if (n->right)
		return (1 + get_tree_size(n->right));
	else
		return (1);
}

int	can_split(struct s_node *n)
{
	int	tree_size = get_tree_size(n);
	if (tree_size % 2 == 0)
		return (1);
	return (0);
}

/* main.c

#include <stdio.h>
#include <stdlib.h>

struct s_node	*cn(int val)
{
	struct s_node	*node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	node->value = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	sn(struct s_node *node)
{
	printf("node: %i\n", node->value);
	if (node->right)
		printf("node right: %i\n", node->right->value);
	if (node->left)
		printf("node left: %i\n", node->left->value);
	printf("\n");
	if (node->right)
		sn(node->right);
	if (node->left)
		sn(node->left);
}

int	main(void)
{
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*c;
	struct s_node	*d;
	struct s_node	*e;
	struct s_node	*f;

	a = cn(0);
	b = cn(1);
	c = cn(2);
	d = cn(3);
	e = cn(4);
	f = cn(5);

	a->right = b;
	a->left = c;

	b->right = d;

	d->right = e;
	d->left = f;

	printf("tree size: %i\n", get_tree_size(a));
	printf("can split? %i\n", can_split(a));
}
*/
