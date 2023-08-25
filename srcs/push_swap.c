#include "push_swap.h"

void	free_nodes(t_stack **list)
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

// Append new node to the previous node
// Start from the head of the list
// Traverse the list to find the last node
// Create a new node and attach it to the last node
void	fill_stack(t_stack **list, int val)
{
	t_stack *last;
	t_stack *new_node;
	
	last = *list;
    while (last->next != NULL)
    {
        last = last->next;
    }
    new_node = create_new_node(val);
    if (!new_node)
    {
        free_nodes(list);
        return ;
    }
    last->next = new_node;
}

/* void	init_stack(t_stack *stack_a)
{
	stack_a->val = 0;
	stack_a->pos = 0;
	stack_a->size = 0;
	stack_a->next = NULL;
} */

void print_stack(const t_stack *list)
{
    while (list != NULL)
    {
        printf("Value:%d\n", list->val);
        list = list->next;
    }
    printf("\n");
}

void print_index(const t_stack *list)
{
    while (list != NULL)
    {
        printf("Index:%d\n", list->index);
        list = list->next;
    }
    printf("\n");
}

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

int	get_rotate_direction(t_stack *stack)
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

void	get_index(t_stack **first_node, int size)
{
	t_stack	*min_node;
	t_stack	*tmp;
	int index;
	int min;

	index = 0;
	tmp = *first_node;
	min_node = NULL;
	while (index < size)
	{
		min = INT_MAX;
		tmp = *first_node;
		while (tmp != NULL /*&& index < size*/)
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
	while (!check_if_descending(*stack_b) && i < size)
	{
		if ((((*stack_b)->index >> bit_pos) & 1) == 0)
			move(rotate, stack_b, 'b');
		else
			push_to(stack_b, stack_a, 'a');
		i++;
	}
}

int	get_max_bits(t_stack *stack)
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

void	ft_big_sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	bit_pos;
	int size; 
	int	max_bits;

	bit_pos = 0;
	max_bits = get_max_bits(*stack_a);
	while (!check_if_ascending(*stack_a) && bit_pos < max_bits)
	{
		size = ft_list_size(*stack_a);
		while (!check_if_ascending(*stack_a) && size--)
		{
			if ((((*stack_a)->index >> bit_pos) & 1) == 1)
				move(rotate, stack_a, 'a');
			else
				push_to(stack_a, stack_b, 'b');
		}
		ft_radix_sort_stackb(stack_a, stack_b, bit_pos + 1);
		bit_pos++;
	}
}

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

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	check_init_errors(argc, argv);
	i = 1;
	stack_a = create_new_node(ft_atoi(argv[i]));
	while (++i < argc)
		fill_stack(&stack_a, ft_atoi(argv[i]));
	if (ft_list_size(stack_a) == 1)
		return (0);
	if (check_if_ascending(stack_a) == false)
		push_swap(&stack_a, &stack_b);

	//print_index(stack_a);
	//printf("Stack A after:\n");
	//print_stack(stack_a);

	free_nodes(&stack_a);
	free(stack_a);
}
