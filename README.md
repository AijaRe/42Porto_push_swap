
# Push Swap

Sorting numbers received as arguments, using 2 stacks and a set of rules.

## Rules
At the beginning:
- The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
- The stack b is empty.

The goal is to sort in ascending order numbers into stack a, using the following movements:

`sa` (swap a): Swap the first 2 elements at the top of stack a.

`sb` (swap b): Swap the first 2 elements at the top of stack b.

`ss` : sa and sb at the same time.

`pa` (push a): Take the first element at the top of b and put it at the top of a.

`pb` (push b): Take the first element at the top of a and put it at the top of b.

`ra` (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

`rb` (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

`rr` : ra and rb at the same time.

`rra` (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

`rrb` (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

`rrr` : rra and rrb at the same time.

