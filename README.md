# PUSH_SWAP

This is my implementation of the push_swap project for the Cursus 42 program, where we are asked to sort an unsorted list of integers using two stacks and a limited set of operations. In this implementation, we will be using the radix sort algorithm to sort the list.

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
2. Use array rotation to locate which ones should be pushed to A or B.
3. Within each iteration, partition the list of integers based on the value of the current digit, and push each partition onto stack B. Then, push the integers from stack B back onto stack A in the correct order.


**Improvements:**

In order to reach a smaller number of movements and get a little more note with this algorithm, some checks are implemented that check whether the total or partial of the stack_a is already ordered to stop the execution and avoid unnecessary movements.

<img width="444" alt="image" src="https://user-images.githubusercontent.com/113030191/229117900-513e1902-3a53-4d00-b238-a73a3d5c3057.png">

- RedRow : To check if the sort is complete.
- GreenRow : To check if the stack_a is sorted.

**Variable management**

I have used structures to carry out the project.

<img width="223" alt="image" src="https://user-images.githubusercontent.com/113030191/229145035-96b0e19c-fa2a-47dc-ac36-18c80be64dea.png">

- This is used once the numbers have been collected, to replace the numbers with what will be your order later and in this way facilitate the code.

<img width="219" alt="image" src="https://user-images.githubusercontent.com/113030191/229145883-ad4fd570-68a2-4fea-90e1-b743be0604a0.png">

- This second structure is used to store the numbers in a two-dimensional array, which is very useful if we have to use the ft_split function, if not necessary, we could do without it.

<img width="418" alt="image" src="https://user-images.githubusercontent.com/113030191/229147022-5276f8db-ae71-4e4f-932b-fe02e19129ad.png">


In this way, we check if the arguments need to be passed by the ft_split function, if not, we pass the memory address of the 2nd argument of argv, to avoid the "./push_swap" argument and in this way we can 100% reuse the function 'fill_a'.

## Checkers

I have used different scripts to check the operation, since the quantities between 2 - 5 have an independent ordering:

- checker_OS : this executable receives the same arguments as 'push_swap' and always returns OK or KO depending on whether the sort is successful or not, on the number of moves allowed or not. An example:

            ./push_swap 9 54 62 -123 756 -12  | ./checker_OS 9 54 62 -123 756 -12 
            OK
- myowntest.sh contains execution of all possible number combinations from 0 - 3, also passing checker_OS.

- myowntest5.sh contains execution of all possible number combinations from 0 - 4, also passing checker_OS.

- push_swap_test.sh is a test carried out by a colleague of 42, this test that checks all the possible error control errors and all the 'OK' for the different levels of number of movements for the effectiveness of the program, its complete execution may take time several minutes, be patient, it's worth it.

- python_visualizer.py is used to do a visual check of the sort process. Here are some execution examples:

1. These first tests are not graphic, but it is the one that allows us to take a random battery of numbers in quantities comprised of (X..Y).

            ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`; ./push_swap $ARG
            ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_OS $ARG 
            
2. This is the test that will give us a visual result of our execution:

            python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

![57738594-6b6ae500-76b0-11e9-9d29-0f59ee825e8e](https://user-images.githubusercontent.com/113030191/229157667-6bc43553-6238-4c4b-94e4-68a448a77dab.gif)

## Conclusion

In conclusion, we have implemented the push_swap project using the radix sort algorithm to sort an unsorted list of integers. The objective of the project is to sort the list in the least number of operations possible, using two stacks and a limited set of operations. The radix sort algorithm is an efficient way to sort integers, and we have seen how we can use it to implement the push_swap project.

### Links to my other projects at 42:

- **[Main Page](../../../Clocon)**
- **[libft](../../../libft-42)**
- **[ft_printf](../../../ft_printf-42)**
- **[get_next_line](../../../get_next_line-42)**
- **[pipex](../../../pipex-42)**
- **[so_long](../../../so_long-42)**
