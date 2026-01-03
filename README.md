*This project has been created as part of the 42 curriculum by <jaa-s>.*

# Push_swap

## Description

`push_swap` is a sorting algorithm project that aims to sort a stack of integers using a limited set of operations and the smallest possible number of moves.

The program takes a list of integers as input, stores them in stack A, and sorts them in ascending order using an auxiliary stack B. Only specific stack operations are allowed, and the program outputs the operations needed to sort the stack.

The main challenge is to design an efficient algorithm, especially for large inputs (100 and 500 numbers).

---

## Instructions

### Compilation

make

Execution
```bash
Copy code
# Sorting example with a few numbers
./push_swap 2 1 3 6 5 8

# Count the number of operations
./push_swap 3 2 1 | wc -l

# Check your sorting with the provided checker (Linux)
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker_linux $ARG

# For 100 random numbers
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

# For 500 random numbers
ARG=$(shuf -i 0-5000 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
Notes
Only valid instructions will be printed (sa, sb, pa, pb, ra, rb, rra, rrb).

Invalid input will print Error and exit.

Optimized to achieve benchmarks for both 100 and 500 numbers.

Resources
42 push_swap subject PDF

C documentation (man pages, stdlib.h, unistd.h)

Articles on sorting algorithms: quicksort, bubble sort, and stack operations

AI assistance was used to:

Explain project logic and linked list operations
Optimize the chunk-based sorting algorithm
Draft README and clarify benchmark validation

Features
Handles any number of valid integers within the 32-bit signed range.

Detects duplicates and invalid input.

Optimized sorting:

Small stacks (2–5 elements) use minimal moves
Large stacks (up to 500 elements) use chunk-based sorting

Fully validated against the checker tool

Author
Janani A S