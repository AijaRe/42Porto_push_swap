/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:52:21 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 11:41:58 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts 3 numbers, choosing movements depending
on the position of the biggest number */
void	ft_sort_3(t_stack **stack_a)
{
	t_stack	*highest_node;

	highest_node = get_max(*stack_a);
	if (*stack_a == highest_node)
		move(rotate, stack_a, 'a');
	else if ((*stack_a)->next == highest_node)
		move(rev_rotate, stack_a, 'a');
	if ((*stack_a)->val > (*stack_a)->next->val)
		move(node_swap, stack_a, 'a');
}

/* Evaluates weather it is better to rotate or 
reverse rotate the stack, depening on the
position of the number. */
static int	get_rotate_direction(t_stack *stack)
{
	int	min;
	int	index;
	int	min_index;
	int	median;

	min = INT_MAX;
	index = 0;
	min_index = 0;
	median = ft_list_size(stack) / 2;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	if (min_index < median)
		return (1);
	else
		return (0);
}

/* Find the smallest value and push to stack B
until 3 numbers are left in stack A.
Sort the 3 numbers in stack A.
Push back from B to A one or two smallest numbers */
void	ft_sort_4_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	rotate_direction;

	while (ft_list_size(*stack_a) > 3)
	{
		min = get_min(*stack_a)->val;
		rotate_direction = get_rotate_direction(*stack_a);
		while ((*stack_a)->val != min)
		{
			if (rotate_direction == 1)
				move(rotate, stack_a, 'a');
			else
				move(rev_rotate, stack_a, 'a');
		}
		push_to(stack_a, stack_b, 'b');
	}
	ft_sort_3(stack_a);
	while (ft_list_size(*stack_b) >= 1)
	{
		push_to(stack_b, stack_a, 'a');
	}
}
