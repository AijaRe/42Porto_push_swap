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
        printf("Node:%d\n", list->val);
        list = list->next;
    }
    printf("\n");
}


void	ft_sort_3(t_stack **stack_a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*stack_a);
	if (*stack_a == highest_node)
		move(rotate, stack_a, 'a');
	else if ((*stack_a)->next == highest_node)
		move(rev_rotate, stack_a, 'a');
	if ((*stack_a)->val > (*stack_a)->next->val)
		move(node_swap, stack_a, 'a');
}

void	push_swap(t_stack **stack_a)
{
	if ((*stack_a)->size == 2)
		move(node_swap, stack_a, 'a');
	if ((*stack_a)->size == 3)
		ft_sort_3(stack_a);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	int i;

	stack_a = NULL;
	if (argc <= 1)
		return (0);
	check_init_errors(argc, argv);
	i = 1;
	stack_a = create_new_node(ft_atoi(argv[i]));
	stack_a->size = 1;
	while (++i < argc)
	{
		fill_stack(&stack_a, ft_atoi(argv[i]));
		stack_a->size++;
	}

	printf("Stack A size: %zu:\n", stack_a->size);
	printf("Stack A before:\n");
	print_stack(stack_a);
	
	if (stack_a->size == 1)
		return (0);
	if (check_sorted(stack_a) == 0)
		push_swap(&stack_a);
	
	printf("Stack A after:\n");
	print_stack(stack_a);

	free_nodes(&stack_a);
	free(stack_a);
}
