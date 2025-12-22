*This project has been created as part of the 42 curriculum by jaa-s.*

# push_swap

## Description

**push_swap** is a sorting algorithm project that aims to sort a stack of integers using a limited set of operations and the smallest possible number of moves.

The program takes a list of integers as input, stores them in **stack A**, and sorts them in ascending order using an auxiliary **stack B**.  
Only specific stack operations are allowed, and the program outputs the operations needed to sort the stack.

The main challenge is to design an efficient algorithm, especially for large inputs (100 and 500 numbers).

---

## Instructions

### Compilation

```bash
make

Execution
bash
Copy code
./push_swap 3 2 1
./push_swap "4 1 3 2"
To count the number of operations:

bash
Copy code
./push_swap 3 2 1 | wc -l
Resources
42 subject PDF: push_swap

Stack-based sorting concepts

Big-O complexity and algorithm optimization

Documentation for C standard library functions

AI Usage
AI tools were used to:

Clarify project requirements

Debug compilation and linking issues

Review Makefile structure

Improve code organization and documentation

All algorithmic decisions and implementation were written and validated by the author.

Rules
Two stacks: a and b

Stack a starts with the input numbers

Stack b starts empty

Only the allowed operations may be used

Each operation must be printed followed by a newline