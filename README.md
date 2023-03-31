# PUSH_SWAP

This is a project for the 42 school curriculum, where we are asked to sort an unsorted list of integers using two stacks and a limited set of operations. In this implementation, we will be using the radix sort algorithm to sort the list.

<img width="1151" alt="image" src="https://user-images.githubusercontent.com/113030191/229107482-11bde195-db18-4e13-a476-f193e2cdb3e5.png">

<img width="598" alt="image" src="https://user-images.githubusercontent.com/113030191/229107856-c498e109-5e69-41b3-a8a0-f28ab35ce24d.png">

The objective of the project is to sort the list of integers in the least number of operations possible. The operations allowed are:

- **sa** - swap the first two elements of stack A.
- **sb** - swap the first two elements of stack B.
- **ss** - swap the first two elements of both stack A and B.
- **pa** - push the first element of stack B onto stack A.
- **pb** - push the first element of stack A onto stack B.
- **ra** - rotate stack A, the first element will become the last.
- **rb** - rotate stack B, the first element will become the last.
- **rr** - rotate both stack A and B.
- **rra** - reverse rotate stack A, the last element will become the first.
- **rrb** - reverse rotate stack B, the last element will become the first.
- **rrr** - reverse rotate both stack A and B.

## Usage

To compile the push_swap program, run the following command: **make**

This will compile the program as **push_swap**, which can be run on the command line.

To use the push_swap program, follow the steps below:

### The push_swap program takes in three two or more arguments:

      ./push_swap "25 -98 65 31 77 ..."
2 arguments, since the numbers enter a single string, for this case we must use [Split](https://github.com/Clocon/libft-42/blob/main/src/ft_split.c).

      ./push_swap 25 -98 65 31 77 ...
3 or more arguments that will directly enter the process of being passed to int and checked.

## Algorithm

We will be using the radix sort algorithm to sort the list of integers. Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.

The algorithm works by iterating through each digit of the numbers in the list, starting with the least significant digit (i.e., the ones place) and working up to the most significant digit (i.e., the highest place value). At each iteration, the algorithm will sort the list based on the value of the digit at the current position. After all iterations, the list will be sorted in ascending order.

Our implementation of the radix classification algorithm will be done in the following steps:

1. Get the maximum number of digits in the list of integers to be sorted.
2. We'll use array rotation to locate which ones should be pushed to A or B.
3. Within each iteration, partition the list of integers based on the value of the current digit, and push each partition onto stack B. Then, push the integers from stack B back onto stack A in the correct order.


**Improvements:**

In order to reach a smaller number of movements and get a little more note with this algorithm, some checks are implemented that check whether the total or partial of the stack_a is already ordered to stop the execution and avoid unnecessary movements.

<img width="444" alt="image" src="https://user-images.githubusercontent.com/113030191/229117900-513e1902-3a53-4d00-b238-a73a3d5c3057.png">
RedRow : To check if the sort is complete.

GreenRow : To check if the stack_a is sorted.

### Links to my other projects at 42:

- **[Main Page](../../../Clocon)**
- **[libft](../../../libft-42)**
- **[ft_printf](../../../ft_printf-42)**
- **[get_next_line](../../../get_next_line-42)**
- **[pipex](../../../pipex-42)**
