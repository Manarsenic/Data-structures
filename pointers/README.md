# Pointers: A Quick Overview of C Pointer Concepts

This folder contains code examples to help understand pointer manipulation and usage in C.

---

### 1. What is a Pointer?

A pointer is a special variable that stores the memory address of another variable. It is a fundamental concept in C programming that allows for direct memory manipulation and efficient data handling.

### 2. Key Pointer Concepts and Code Examples

#### A. Basic Declaration and Dereferencing

A pointer must be declared to point to a specific data type. The `&` operator is used to get the address of a variable, and the `*` operator is used to dereference a pointer to access the value at that address.

```c
#include <stdio.h>

int main() {
    int num = 10;   // Declare a regular integer variable
    int *pnum;      // Declare a pointer to an integer

    pnum = &num;    // Assign the address of 'num' to 'pnum'

    printf("The value of num is: %d\n", num);
    printf("The address of num is: %p\n", &num);
    printf("The value stored in pnum is: %p\n", pnum);
    printf("The value at the address pnum points to is: %d\n", *pnum);

    return 0;
}
