/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:36:10 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 10:36:38 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap operation in both stacks
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	node_swap(stack_a);
	node_swap(stack_b);
	ft_printf("ss\n");
}

// Rotate operation in both stacks
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

// Reverse rotate operation in both stacks
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
}
