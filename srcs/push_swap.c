/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:59:46 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 14:07:50 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_nodes(t_stack **list)
{
	t_stack	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	*list = NULL;
}

/* Create a new node with parameter value.
If the list is empty, make the new node the head of the list.
Find the last node of the list.
Update the last nodes next pointer to point to the new node. */
static void	fill_stack(t_stack **head, int val)
{
	t_stack	*last;
	t_stack	*new_node;

	new_node = create_new_node(val);
	if (!new_node)
	{
		free_nodes(head);
		return ;
	}
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
}

/* direct stack to corresponding sort */
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_list_size(*stack_a) == 2)
		move(node_swap, stack_a, 'a');
	else if (ft_list_size(*stack_a) == 3)
		ft_sort_3(stack_a);
	else if (ft_list_size(*stack_a) <= 5)
		ft_sort_4_5(stack_a, stack_b);
	else if (ft_list_size(*stack_a) > 5)
	{
		get_index(stack_a, ft_list_size(*stack_a));
		ft_big_sort_radix(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	check_init_errors(argc, argv);
	i = 1;
	while (i < argc)
	{
		fill_stack(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	if (check_if_ascending(stack_a) == false)
		push_swap(&stack_a, &stack_b);
	free_nodes(&stack_a);
	free(stack_a);
}
