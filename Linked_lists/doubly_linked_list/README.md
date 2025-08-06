# Doubly Linked List in C

[![C Language](https://img.shields.io/badge/Language-C-blue.svg)](https://www.gnu.org/software/gcc/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Overview

This project is a basic implementation of a **Doubly Linked List** data structure in the C programming language. Unlike a singly linked list, a doubly linked list allows for traversal in both forward and backward directions, as each node contains a pointer to the next node and a pointer to the previous node.

This implementation demonstrates the fundamental operations required to manage a doubly linked list, including insertion and printing.

## Visual Representation

A doubly linked list can be visualized as a chain of nodes, where each node is connected to its predecessor and successor.

+-------+     +-------+     +-------+
| PREV  | --> | PREV  | --> | PREV  |
|       |     |       |     |       |
| DATA  |     | DATA  |     | DATA  |
|       |     |       |     |       |
| NEXT  | --> | NEXT  | --> | NEXT  | --> NULL
+-------+     +-------+     +-------+
^           ^           ^
|           |           |
NULL <--------- <---------


Each box represents a `Node` containing:
* `prev`: A pointer to the previous node.
* `data`: The value stored in the node.
* `next`: A pointer to the next node.

## How to Use

Follow these steps to compile and run the doubly linked list code.

### 1. Compile the Code
Navigate to the directory containing `doubly_linked_list.c` and use a C compiler to build the executable.

`gcc doubly_linked_list.c -o doubly_linked_list`

### 2. Run the Executable
Run the compiled program to see the doubly linked list in action.

`./doubly_linked_list`

## Functions Implemented

The `doubly_linked_list.c` file contains the following functions:

* `struct Node`: Defines the structure of a node.
* `insert_end(int value)`: Inserts a new node with a given value at the end of the list.
* `insert_beginning(int value)`: Inserts a new node at the beginning of the list.
* `print_list()`: Traverses the list from the head and prints the data of each node.
* `print_list_reverse()`: Traverses the list from the tail and prints the data of each node in reverse order.
* `main()`: A driver function to demonstrate the basic usage of the other functions.

## Further Enhancements

This project can be expanded with more functionalities to create a more robust data structure. Suggested enhancements include:
* `delete_node(int value)`: Deletes the first node with the specified value.
* `insert_at_position(int value, int position)`: Inserts a node at a given position.
* `search_node(int value)`: Searches for and returns a node with a given value.

## License

This project is licensed under the [MIT License](LICENSE).
