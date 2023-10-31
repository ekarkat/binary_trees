# Binary Trees in C

## Overview

This is a group project for the course, "Data Structures and Algorithms," focusing on binary trees in the C programming language. The project is to be done in teams, and this team consists of Alexandre Gautier and Almahdi Kerdoud.

The project is scheduled to start on October 30, 2023, at 3:00 AM, and must be completed by November 3, 2023, at 3:00 AM. A checker was released on October 31, 2023, at 3:00 AM, and an auto-review will be launched at the deadline.


## Learning Objectives

By the end of this project, you should be able to explain the following concepts without external assistance:

### General

- What is a binary tree
- The difference between a binary tree and a Binary Search Tree
- The potential advantages in terms of time complexity compared to linked lists
- The concepts of depth, height, and size of a binary tree
- Different traversal methods to go through a binary tree
- What is a complete, full, perfect, and balanced binary tree

## Copyright and Plagiarism

It is crucial to come up with your own solutions for the tasks in this project to meet the learning objectives. Plagiarism is strictly forbidden, and any form of it will result in removal from the program.

## Requirements

### General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, with the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file at the root of the project folder is mandatory
- Your code should follow the Betty style and will be checked using `betty-style.pl` and `betty-doc.pl`
- You are not allowed to use global variables
- A maximum of 5 functions per file
- You are allowed to use the standard library
- The prototypes of all your functions should be included in your header file called `binary_trees.h`
- Don't forget to push your header file
- All your header files should be include guarded

## More Info

### Data Structures

Please use the following data structures and types for binary trees, which should be included in your `binary_trees.h` header file:

### Basic Binary Tree

```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

### Print function
To match the examples in the tasks, you are given [this function] (https://github.com/alx-tools/0x1C.c)

This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction

