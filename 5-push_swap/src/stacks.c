/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:57:03 by swillis           #+#    #+#             */
/*   Updated: 2022/02/08 17:50:40 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int n, int bin)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (0);
	elem->val = n;
	elem->bin = bin;
	elem->next = 0;
	elem->prev = 0;
	return (elem);
}

t_node	*last_node(t_node **stack)
{
	t_node	*top;
	t_node	*elem;

	top = *stack;
	if (top)
	{
		elem = top;
		while (elem->next)
			elem = elem->next;
		return (elem);
	}
	else
		return (0);
}

void	stack_push(t_node **stack, t_node *new)
{
	t_node	*top;

	top = *stack;
	if (top)
	{
		top->prev = new;
		new->next = top;
		*stack = new;
	}
	else
		*stack = new;
}

void	stack_pop(t_node **stack)
{
	t_node	*top;
	t_node	*tmp;

	top = *stack;
	if (top)
	{
		tmp = top;
		top = top->next;
		if (top)
			top->prev = 0;
		*stack = top;
		free(tmp);
	}
}

t_node	**stack_init(int *array, int len)
{
	int		i;
	t_node	**stack;
	t_node	*new;

	i = len - 1;
	if (len > 1)
	{
		stack = malloc(sizeof(t_node *));
		if (!stack)
			return (0);
		*stack = 0;
		while (i >= 0)
		{
			new = new_node(array[i], 0);
			if (!new)
				return (0);
			stack_push(stack, new);
			i--;
		}
		return (stack);
	}
	else
		return (0);
}
