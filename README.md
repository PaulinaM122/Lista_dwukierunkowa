# Doubly Linked List Implementation

## Description

This project contains an implementation of a doubly linked list in C++. The doubly linked list consists of nodes, each containing a data field and pointers to the next and previous nodes in the list.

## File

- **Lista_dwukierunkowa.cpp**: This file contains the implementation of the doubly linked list along with the main program logic.

## Operations

### 1. Insertion

- **Insertion Before**: Inserts a new node before a specified node in the list.
- **Insertion After**: Inserts a new node after a specified node in the list.
- **Add First**: Adds a new node at the beginning of the list.
- **Add Last**: Adds a new node at the end of the list.

### 2. Removal

- **Remove Node**: Removes a specified node from the list.

### 3. Iteration

- **Initialize Iterator**: Initializes an iterator at a specified position in the list.
- **Move Forward**: Moves the iterator forward to the next node in the list.
- **Move Backward**: Moves the iterator backward to the previous node in the list.

### 4. Printing

- **Print List**: Prints the entire contents of the list.

## Usage

To use the program, compile the `Lista_dwukierunkowa.cpp` file using a C++ compiler. Then run the compiled executable.

Example compilation using g++:

```bash
g++ Lista_dwukierunkowa.cpp -o doubly_linked_list
```

To run the compiled program:

```bash
./doubly_linked_list
```

## Input Format

The program accepts input commands to perform various operations on the doubly linked list. The input commands are specified using the following format:

- `.` followed by either `B` or `E` to specify insertion at the beginning or end respectively, followed by the data value.
- `A` followed by either `B` or `E` to specify insertion before or after respectively, followed by the index or iterator number and the data value.
- `i` followed by the iterator number to initialize the iterator at a specific position in the list.
- `+` or `-` followed by the iterator number to move the iterator forward or backward respectively.
- `R` followed by either `B` or `E` to specify removal from the beginning or end respectively, or followed by the index or iterator number for removal at a specific position.
- `P` followed by either `A` or the iterator number to print the entire list or the data value at the specified iterator respectively.

## Author

Author: [Paulina Machcińska](https://github.com/PaulinaM122)
