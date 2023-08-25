#include "push_swap.h"

void ft_exit_error()
{
	write(2, "Error\n", 6);
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
	new_node->has_index = false;
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

int	ft_list_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
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
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_exit_error();
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	if (sign == -1)
		return (-nb);
	return (nb);
}
