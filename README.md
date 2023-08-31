
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

## Materials
[Push Swap explained (medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

[Push Swap — A journey to find most efficient sorting algorithm (medium)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

[Insertion sort in small chunks (medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

[Push Swap Radix tutorial (medium)](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

[Oceano - Push Swap](https://www.youtube.com/watch?v=OaG81sDEpVk)

[Sorting algorithms explained visually](https://www.youtube.com/watch?v=RfXt_qHDEPw)

[Integer overflow](https://www.scaler.com/topics/c/overflow-and-underflow-in-c/)


## Push Swap Plan
Check if input is not empty.

Convert input to integers using atol (inside error check)

Perform input error checks:
 - non-numeric characters
 - >INT_MAX || < INT_MIN

 - double numbers

 - empty string

Create/initialize node 

Create node stack

 - find last node

 - append node

Get stack size

Implement push_swap commands: 

 - swap

 - rotate

 - reverse rotate

 - push

Check if the list is already sorted.

Sort 2, sort 3, sort 4 & 5

Algorithm. Radix sort, using binary.

 - Assign an index (positive number) to all the numbers, starting from smallest number. Create a flag “has_index” in the structure to be able to skip assigned numbers withing the loop.

 - Sort the numbers by their index.

 - Start with least significant bit, push all numbers that end with 0 from stack A to stack B.

 - If not a 0, rotate stack to move to the next number.

 - Optimization: In stack B, before pushing everything back to stack A, check if the bit before the one that was analyzed in stack A is also a 0. If so, no need to move, rotate the numbers. If the previous bit is 1, push back from B to A.

 - Check the next bit until all bits are sorted.

 - Free memory. Since all error checks were done before creating the stack and all the movements were done, using pointers to the pointers to nodes of stack A, only need to free the nodes of stack A at the end of the program.


## Number of moves
|      | **100** | **500** |
| ---- | ------- | ------- |
| min  | 855     | 5739    |
| max  | 857     | 5741    |

Radix algorithm is very stable :) 

(and therefore not flexible)

## Deployment

To deploy this project run

```
  make
```
To see the list of movements run the executable followed by the list of arguments
```
./push_swap 2 1 -3 5
```

Syntax for passing argument list in zsh: `ARG="4 67 3 87 23”; ./push_swap ${=ARG} | ./checker ${=ARG}`

Syntax for passing argument list in bash: `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`



