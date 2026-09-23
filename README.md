# C Algorithms & Generic Memory Operations

A command-line application written in C that demonstrates fundamental programming concepts including sorting algorithms, pointers, dynamic memory allocation, and generic memory operations.

The program contains two main components: sorting integer arrays using classic sorting algorithms and a generic swap function capable of swapping values of different data types.

## Features

### Sorting Algorithms

Users can enter a custom array of integers and choose between two sorting algorithms:

- Insertion Sort
- Selection Sort

The program displays the array before and after sorting.

### Generic Swap Function

Implements a reusable `genericSwap()` function using `void` pointers and raw memory operations.

The function supports swapping:

- Integers
- Floating-point numbers
- Strings

The implementation uses `memcpy()` and dynamically allocated temporary memory, allowing the same function to operate on different data types.

## Concepts Demonstrated

- C pointers and `void *`
- Dynamic memory allocation with `malloc()` and `free()`
- Memory manipulation using `memcpy()`
- Insertion Sort
- Selection Sort
- Arrays and strings
- Functions and modular program structure
- Command-line input and menu navigation

## Technology

- C

## Example

```text
1. Project 1 – Sorting Algorithms
2. Project 2 – Generic Swap Function
3. Exit Program

Select one of the above programs to run: 1

Project 1: Sorting
Enter number of elements: 6
Enter 6 integers: 42 8 17 3 29 11

Unsorted array: 42 8 17 3 29 11

Choose sorting algorithm:
1. Insertion Sort
2. Selection Sort

Enter choice: 1

Sorted using Insertion Sort:
3 8 11 17 29 42
```

## Project Structure

```text
.
├── CMakeLists.txt
├── main.c
└── README.md
```

## Purpose

This project was created to practice core C programming concepts and gain experience working with algorithms, pointers, dynamic memory management, and generic functions.