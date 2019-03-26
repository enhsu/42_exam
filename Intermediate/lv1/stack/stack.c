/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:25:45 by exam              #+#    #+#             */
/*   Updated: 2019/03/26 10:38:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	struct s_node	*tmp;

	if (!(stack->top))
		return (NULL);
	tmp = stack->top;
	stack->top = stack->top->next;
	return (tmp->content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node	*tmp;

	tmp = (struct s_node*)malloc(sizeof(struct s_node));
	tmp->content = content;
	tmp->next = stack->top;
	stack->top = tmp;
}

void *peek(struct s_stack *stack)
{
	if (!(stack->top))
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!(stack->top))
		return (1);
	return (0);
}

/* main.c
#include <stdio.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void);

void *pop(struct s_stack *stack);

void push(struct s_stack *stack, void *content);

void *peek(struct s_stack *stack);

int isEmpty(struct s_stack *stack);

void	ss(struct s_stack *stack)
{
	int				i = 0;
	struct s_node	*tmp;
	tmp = stack->top;

	while (tmp)
	{
		printf("stack %i: %s\n", i, tmp->content);
		i++;
		tmp = tmp->next;
	}
}

int	main(void)
{
	struct s_stack	*stack;

	stack = init();
	push(stack, "123");
	push(stack, "223");
	push(stack, "aaa");
	ss(stack);
	printf("peek stack: %s\n", peek(stack));
	printf("pop stack: %s\n", pop(stack));
	printf("is stack empty? %i\n", isEmpty(stack));
	ss(stack);
	printf("peek stack: %s\n", peek(stack));
	printf("pop stack: %s\n", pop(stack));
	printf("is stack empty? %i\n", isEmpty(stack));
	ss(stack);
	printf("peek stack: %s\n", peek(stack));
	printf("pop stack: %s\n", pop(stack));
	printf("is stack empty? %i\n", isEmpty(stack));
	ss(stack);
	printf("peek stack: %s\n", peek(stack));
	printf("pop stack: %s\n", pop(stack));
	printf("is stack empty? %i\n", isEmpty(stack));
	push(stack, "666");
	ss(stack);
}
*/
