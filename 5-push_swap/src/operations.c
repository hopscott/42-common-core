/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:01:34 by swillis           #+#    #+#             */
/*   Updated: 2022/02/08 17:13:39 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_node **stackA)
{
	stack_swap(stackA);
	ft_putstr("sa\n");
}

void	op_sb(t_node **stackB)
{
	stack_swap(stackB);
	ft_putstr("sb\n");
}

void	op_ss(t_node **stackA, t_node **stackB)
{
	stack_swap(stackA);
	stack_swap(stackB);
	ft_putstr("ss\n");
}

void	op_pa(t_node **stackA, t_node **stackB)
{
	t_node	*top;
	t_node	*elem;

	if (*stackB)
	{
		top = *stackB;
		elem = copy_node(top);
		stack_push(stackA, elem);
		stack_pop(stackB);
	}
	ft_putstr("pa\n");
}

void	op_pb(t_node **stackA, t_node **stackB)
{
	t_node	*top;
	t_node	*elem;

	if (*stackA)
	{
		top = *stackA;
		elem = copy_node(top);
		stack_push(stackB, elem);
		stack_pop(stackA);
	}
	ft_putstr("pb\n");
}
