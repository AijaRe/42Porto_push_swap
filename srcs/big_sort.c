/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:54:57 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 14:37:21 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* get a positive index for all the numbers
find the node with smallest value and attribute index 0
flag as indexed node
find the smallest non-flagged node... */
void	get_index(t_stack **head, int size)
{
	t_stack	*min_node;
	t_stack	*tmp;
	int		index;
	int		min;

	index = 0;
	tmp = *head;
	min_node = NULL;
	while (index < size)
	{
		min = INT_MAX;
		tmp = *head;
		while (tmp != NULL)
		{
			if (tmp->val < min && tmp->has_index == false)
			{
				min_node = tmp;
				min = tmp->val;
			}
			tmp = tmp->next;
		}
		min_node->index = index;
		min_node->has_index = true;
		index++;
	}
}

/* find the biggest index
count how many bits it has */
static int	get_max_bits(t_stack *stack)
{
	int	max_bits;
	int	max;

	max_bits = 0;
	max = get_max(stack)->index;
	while (max > 0)
	{
		max_bits++;
		max = max >> 1;
	}
	return (max_bits);
}

/* sort stack B
If the bit before the one that was analyzed in stack A is 0,
leave it it stack B since it is already in the correct place. 
Rotate stack B to get the next node.
If the previous bit is 1, push back to stack A. */
void	ft_radix_sort_stackb(t_stack **stack_a, t_stack **stack_b, int bit_pos)
{
	int	size;
	int	i;

	size = ft_list_size(*stack_b);
	i = 0;
	if (check_if_ascending(*stack_a) && check_if_descending(*stack_b))
	{
		while (i++ < size)
			push_to(stack_b, stack_a, 'a');
	}
	i = 0;
	while (*stack_b != NULL && i < size)
	{
		if ((((*stack_b)->index >> bit_pos) & 1) == 0)
			move(rotate, stack_b, 'b');
		else
			push_to(stack_b, stack_a, 'a');
		i++;
	}
}

/* Check the least significant bit.
If it is 0, push node to stack B.
If it is 1, rotate stack A to get to the next node. */
void	ft_big_sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	bit_pos;
	int	size; 
	int	i;
	int	max_bits;

	bit_pos = 0;
	max_bits = get_max_bits(*stack_a);
	while (bit_pos < max_bits)
	{
		i = 0;
		size = ft_list_size(*stack_a);
		while (!check_if_ascending(*stack_a) && i < size)
		{
			if ((((*stack_a)->index >> bit_pos) & 1) == 1)
			{
				move(rotate, stack_a, 'a');
			}
			else
				push_to(stack_a, stack_b, 'b');
			i++;
		}
		ft_radix_sort_stackb(stack_a, stack_b, bit_pos + 1);
		bit_pos++;
	}
}
