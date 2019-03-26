/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:56:51 by exam              #+#    #+#             */
/*   Updated: 2019/03/26 10:39:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node	*head;
	struct s_node	*tmp;
	head = root;

	tmp = head->left;
	head->left = head->right;
	head->right = tmp;
	if (head->left)
		reverse_tree(head->left);
	if (head->right)
		reverse_tree(head->right);
}

/* main.c
#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root);

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

	sn(a);
	printf("reverse tree\n");
	reverse_tree(a);
	sn(a);
}
*/
