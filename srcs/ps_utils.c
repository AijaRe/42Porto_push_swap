#include "push_swap.h"

void ft_exit_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_intcmp(int a, int b)
{
	return (a - b);
}

t_stack	*create_new_node(int val)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

// Returns the last node of a linked list
t_stack	*last_node(t_stack *top)
{
	while (top && top->next)
		top = top->next;
	return (top);
}

// Returns the second last node of a linked list
t_stack	*second_last_node(t_stack *top)
{
	while (top && top->next && top->next->next)
		top = top->next;
	return (top);
}

// Adds a new node to the top of a list
void	push_new_val(t_stack **top, int val)
{
	t_stack	*new_top;

	new_top = create_new_node(val);
	new_top->next = *top;
	*top = new_top;
}

// Returns the node with the highest value
t_stack	*find_highest(t_stack *stack)
{
	int		highest_val;
	t_stack	*highest_node;

	if (!stack)
		return (NULL);
	highest_val = INT_MIN;
	while (stack)
	{
		if (stack->val > highest_val)
		{
			highest_val = stack->val;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

// Checks if given stack is sorted
int	check_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val < stack->next->val)
			return (1);
		stack = stack->next;
	}
	return (0);
}
long	ft_atol(char *str)
{
	int	i;
	int	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		return (-nb);
	return (nb);
}
