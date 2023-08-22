#include "push_swap.h"

// Swap the first 2 elements at the top of a stack
void	node_swap(t_stack **top)
{
	t_stack	*temp;

	temp = (*top)->next;
	(*top)->next = (*top)->next->next;
	temp->next = (*top);
	(*top) = temp;
}

// Shift up all elements of a stack by 1
void	rotate(t_stack **top)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *top;
	(*top) = (*top)->next;
	temp->next = NULL;
	last = last_node(*top);
	last->next = temp;
}

// Shift down all elements of a stack by 1
void	rev_rotate(t_stack **top)
{
	t_stack	*last;
	t_stack	*second_last;

	last = last_node(*top);
	second_last = second_last_node(*top);
	second_last->next = NULL;
	last->next = *top;
	*top = last;
}

// Push first element of stack 1 to the top of stack 2
// by creating a new node on stack 2 with the value of 
// the node on top of stack 1 and freeing the latter
void	push_to(t_stack **top_1, t_stack **top_2, char list)
{
	t_stack	*temp;

	push_new_val(top_2, (*top_1)->val);
	temp = (*top_1);
	*top_1 = (*top_1)->next;
	free(temp);
	write(1, "p", 1);
	write(1, &list, 1);
	write(1, "\n", 1);
}

// Controls which operation to do and to which stack
void	move(void (*operation)(t_stack**), t_stack **stack, char list)
{
	if (!stack)
		return ;
	operation(stack);
	if (operation == node_swap)
		write(1, "s", 1);
	else if (operation == rotate)
		write(1, "r", 1);
	else if (operation == rev_rotate)
		write(1, "rr", 2);
	write(1, &list, 1);
	write(1, "\n", 1);
}

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