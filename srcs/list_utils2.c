/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:14:21 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 11:47:38 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the node with the highest value
t_stack	*get_max(t_stack *stack)
{
	int		max_val;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_val = INT_MIN;
	while (stack)
	{
		if (stack->val > max_val)
		{
			max_val = stack->val;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

// Returns the node with the lowest value
t_stack	*get_min(t_stack *stack)
{
	int		min_val;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_val = INT_MAX;
	while (stack)
	{
		if (stack->val < min_val)
		{
			min_val = stack->val;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

// Checks if given stack is sorted in ascending order
bool	check_if_ascending(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// Checks if given stack is sorted in descending order
bool	check_if_descending(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val < stack->next->val)
			return (false);
		stack = stack->next;
	}
	return (true);
}
