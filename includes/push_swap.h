#include <stdio.h>
/* read, write */
#include <unistd.h>
/* malloc, free, exit */
#include <stdlib.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_stack{
	int val;
	int pos;
	size_t size;
	struct s_stack *next;
} t_stack;

/* libft */
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
/* push_swap.c */
int main(int argc, char **argv);
t_stack	*create_new_node(int val);
/* check_init_errors.c */
int check_init_errors(int argc, char **argv);
/* ps_utils.c */
void ft_exit_error();
int	ft_intcmp(int a, int b);
long	ft_atol(char *str);
t_stack	*last_node(t_stack *top);
t_stack	*second_last_node(t_stack *top);
void	push_new_val(t_stack **top, int val);
t_stack	*find_highest(t_stack *stack);
int	check_sorted(t_stack *stack);
/* operations.c */
void	node_swap(t_stack **top);
void	rotate(t_stack **top);
void	rev_rotate(t_stack **top);
void	push_to(t_stack **top_1, t_stack **top_2, char list);
void	move(void (*operation)(t_stack**), t_stack **stack, char list);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void print_stack(const t_stack *list);