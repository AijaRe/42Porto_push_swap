/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:54:00 by arepsa            #+#    #+#             */
/*   Updated: 2023/08/28 11:54:01 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* read, write */
#include <unistd.h>
/* malloc, free, exit */
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "../libft/libft.h"

typedef struct s_stack{
	int				val;
	int				index;
	bool			has_index;
	struct s_stack	*next;
}	t_stack;

/* push_swap.c */
int		main(int argc, char **argv);
t_stack	*create_new_node(int val);
/* check_init_errors.c */
int		check_init_errors(int argc, char **argv);
/* atol.c */
long	ft_atol(char *str);
/* list_utils1.c */
void	ft_exit_error(void);
t_stack	*create_new_node(int val);
t_stack	*last_node(t_stack *top);
t_stack	*second_last_node(t_stack *top);
int		ft_list_size(t_stack *stack);
/* list_utils2.c */
t_stack	*get_max(t_stack *stack);
t_stack	*get_min(t_stack *stack);
bool	check_if_ascending(t_stack *stack);
bool	check_if_descending(t_stack *stack);
/* operations1.c */
void	node_swap(t_stack **top);
void	rotate(t_stack **top);
void	rev_rotate(t_stack **top);
void	push_to(t_stack **top_1, t_stack **top_2, char list);
void	move(void (*operation)(t_stack**), t_stack **stack, char list);
/* operations2.c */
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* small_sort.c */
void	ft_sort_3(t_stack **stack_a);
void	ft_sort_4_5(t_stack **stack_a, t_stack **stack_b);
/* big_sort.c */
void	get_index(t_stack **first_node, int size);
void	ft_radix_sort_stackb(t_stack **stack_a, t_stack **stack_b, int bit_pos);
void	ft_big_sort_radix(t_stack **stack_a, t_stack **stack_b);
