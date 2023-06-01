/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:01:18 by swillis           #+#    #+#             */
/*   Updated: 2022/02/08 17:09:32 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_node **stackA)
{
	stack_rotate(stackA);
	ft_putstr("ra\n");
}

void	op_rb(t_node **stackB)
{
	stack_rotate(stackB);
	ft_putstr("rb\n");
}

void	op_rr(t_node **stackA, t_node **stackB)
{
	stack_rotate(stackA);
	stack_rotate(stackB);
	ft_putstr("rr\n");
}
