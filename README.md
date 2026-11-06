# Push Swap

A C implementation of the 42 school project `push_swap`, which sorts a stack of integers using two stacks (`a` and `b`) and a restricted set of operations.

## Project goal

The goal is to sort a list of integers in ascending order with the lowest possible number of operations using only these stack operations:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

The project focuses on algorithmic efficiency and input validation.

## Features

- Parses integers from command-line arguments
- Handles multiple arguments and whitespace-separated values
- Rejects invalid input, duplicates, and integer overflow
- Sorts the stack using a custom stack-based algorithm
- Includes a checker-compatible bonus target

## Build

From the project root:

```bash
make
```

This builds the executable:

```bash
./push_swap
```

## Usage

```bash
./push_swap 3 2 1 5 4
```

Example output:

```bash
sa
pb
ra
...
```

The program prints the sequence of operations needed to sort the stack.

## Bonus

The project includes a checker program for validating a sorting sequence:

```bash
make bonus
```

This builds:

```bash
./checker
```

You can then feed the program a list of numbers and a sequence of operations to verify whether the stack ends sorted.

## Cleanup

```bash
make clean
make fclean
```

## Notes

- Input values must be integers within the range of `int`.
- Duplicate numbers are not allowed.
- The program exits with an error if the input is invalid.

## Author

Ilyben2004
