/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:58:16 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 14:55:31 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first 2 elements at the top of a stack */
void	node_swap(t_stack **head)
{
	t_stack	*temp;

	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	temp->next = (*head);
	(*head) = temp;
}

/* Shift up all elements of a stack by 1.
First node will become the last node.
Set temp to point to the first node.
Head points to the second node.
Temp next pointer set to null.
Last node next points to temp. */
void	rotate(t_stack **head)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *head;
	(*head) = (*head)->next;
	temp->next = NULL;
	last = last_node(*head);
	last->next = temp;
}

/* Shift down all elements of a stack by 1. 
Disconnect last node by setting the second last node
next pointer to NULL.
Set next ponter of the last node to point to the first node.
Head is updated to pint to the last node.*/
void	rev_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*second_last;

	last = last_node(*head);
	second_last = second_last_node(*head);
	second_last->next = NULL;
	last->next = *head;
	*head = last;
}

/*  Push first element of stack 1 to the top of stack 2.
Tmp points to the node that will be moved 
(same node thats source head points to).
*source head pointer is updated to point to the next node.
If dst stack is empty, tmp becomes it's only node.
If dst contains nodes, set the next pointer of tmp
to point to the top of the dst stack. 
Then set the head to point to the same node as tmp */
void	push_to(t_stack **src_head, t_stack **dst_head, char list)
{
	t_stack	*tmp;

	tmp = *src_head;
	*src_head = (*src_head)->next;
	if (*dst_head == NULL)
	{
		*dst_head = tmp;
		(*dst_head)->next = NULL;
	}
	else
	{
		tmp->next = *dst_head;
		*dst_head = tmp;
	}
	write(1, "p", 1);
	write(1, &list, 1);
	write(1, "\n", 1);
}

// Controls which operation to do and to which stack
void	move(void (*operation)(t_stack**), t_stack **head, char list)
{
	if (!head)
		return ;
	operation(head);
	if (operation == node_swap)
		write(1, "s", 1);
	else if (operation == rotate)
		write(1, "r", 1);
	else if (operation == rev_rotate)
		write(1, "rr", 2);
	write(1, &list, 1);
	write(1, "\n", 1);
}
