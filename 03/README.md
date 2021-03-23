# Assignment 3 for April 13th, 2021

The goal of this assignment is to get to know the basic functionality of OpenMP.

## Exercise 1 (1 Point)

### Description

This exercise consists of implementing the Monte Carlo Pi approximation of assignment 02 in OpenMP.    

### Tasks

- Implement parallel versions of the Monte Carlo Pi approximation of assignment 02 using OpenMP. In total, three different versions using the following OpenMP constructs should be provided:
    - `critical` section
    - `atomic` statement
    - `reduction` clause
- Benchmark your parallel implementations with 1, 2, 4, and 8 threads on LCC2 using n=500,000,000 using OpenMP's time measurement function. What can you observe? How do those results compare to your measurements in Assignment 02?
- The tool `/usr/bin/time` can be used to get useful information on the properties of a program's execution, e.g. its execution time or the maximum amount of main memory used. Measure the execution time of your OpenMP implementation using `/usr/bin/time -v <program_name>`. Take a look at the output, specifically "user time" and "elapsed (wall clock) time". How do they differ? Does either of them match the time measurement function of OpenMP?
- Add the wall clock time measurements for 8 threads on LCC2 to the comparison spreadsheet linked on Discord.

## Exercise 2 (1 Point)

### Description

This exercise deals with performance analysis and improvement of a given [code](ex2/ex2.c). The program reads a matrix size n from the command-line. Then two square matrices a and b of size n\*n are filled with random numbers. Finally, the program should print the sum of all elements of matrix c and the wall clock time after the matrix multiplication c=a\*b was conducted. 

### Tasks

- Are there any (performance) issues in the given code? Document your findings.
- Improve the performance of the given source code. 
- Benchmark your modification of the code and the original implementation with 1, 2, 4, and 8 threads on LCC2 using n=1,500. Has your effort paid off?
- Enter your shortest wall clock time for 8 threads and n=1,500 on LCC2 to the comparison spreadsheet linked on Discord.

## Exercise 3 (1 Point)

### Description

In this exercise, you are asked to implement merge sort for arrays of type `int32_t *`. The input for your program should be the size of the array to sort. The generated array should be filled randomly using a pseudo-random number generator provided in `stdlib.h`.

### Tasks

- Implement a sequential, iterative version of merge sort.
- Create a set of tests to ensure that the algorithm sorts properly. You need not to use a unit testing framework.
- Implement a parallel, iterative version of merge sort using OpenMP.
- Enter the wall clock time of the sequential version, and the parallel version for 1 and 8 threads for n=100,000,000 on LCC2 to the comparison spreadsheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
