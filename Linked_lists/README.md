# Linked Lists in C

This directory contains C implementations of various types of linked lists, which are fundamental dynamic data structures. The concepts and operational principles presented here reflect my understanding and learning, significantly shaped by comprehensive study resources on Data Structures.

## 📚 Introduction to Linked Lists and Their Fundamental Use

A linked list is a linear collection of data elements, which are commonly referred to as **nodes**. It is a very flexible, dynamic data structure in which elements (nodes) form a sequential list. Unlike static arrays, a programmer need not worry about the maximum number of elements that will be stored in the linked list. This characteristic allows developers to write robust programs that can adapt to varying data quantities without worrying about memory limitations.

### Basic Terminologies

* **Node**: Each individual element within a linked list.
* **Data Field**: The part of a node that holds the actual information or value. This can be of any data type, such as an integer, a character, or even a more complex structure.
* **Next Pointer/Link**: A crucial part of a node that stores the memory address (or a reference/link) to the subsequent node in the sequence. This pointer is what connects the nodes to form a chain.
* **`NULL` (or X / -1)**: A special value stored in the `next` field of the last node in a list to signify the end or tail of the list.
* **`START` Pointer**: A primary pointer variable that holds the memory address of the very first node in the entire linked list. If `START` is `NULL`, it signifies that the linked list is currently empty.
* **Self-Referential Data Type**: A node in a linked list is considered self-referential because its structure definition includes a pointer type that points back to itself (i.e., a pointer to another node of the same structure).

### Why Use Linked Lists?

Linked lists are indispensable in programming because they address several limitations inherent in static arrays:
* **Dynamic Size**: One of their foremost advantages is the ability to grow or shrink in size during the program's execution, adapting dynamically to the amount of data. This eliminates the need to pre-define a fixed maximum capacity.
* **Efficient Insertion and Deletion**: Unlike arrays, where insertions and deletions often require shifting numerous subsequent elements (a time-consuming O(n) operation), linked lists facilitate these operations efficiently. By simply modifying a few pointers, insertions and deletions can often be achieved in constant time (O(1)), provided the location for modification is known.
* **Non-Contiguous Memory Allocation**: Nodes can be stored anywhere in memory, not necessarily next to each other, making memory utilization more flexible.
* **Foundation for Other Structures**: They serve as fundamental building blocks for implementing more intricate data structures, such as various types of stacks, queues, hash tables (via chaining), and certain tree and graph representations.

## 🆚 Comparison: Linked Lists versus Arrays

While both arrays and linked lists are fundamental linear data structures designed to store collections of data, their internal mechanisms and optimal use cases differ significantly:

| Feature                   | Arrays                                                                                                                                                                             | Linked Lists                                                                                                                                                                                                                                                                                                                                                                                                                          |
| :------------------------ | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Memory Allocation** | Elements are stored in **contiguous (adjacent)** memory locations. The entire block of memory is typically allocated as a single unit at compile-time or program initialization. | Nodes are **not necessarily stored in consecutive** memory locations. Memory for each node is dynamically allocated individually at runtime, often from the heap, and linked together via pointers. |
| **Size Limitation** | Have a **fixed size**; the maximum number of elements must be declared upfront and cannot be easily changed. Resizing an array (if supported by the language) typically involves creating a new, larger array and copying all elements. | Possess a **dynamic size**; the number of elements can easily grow or shrink during the program's execution. This adaptability is limited only by the available system memory. |
| **Data Access** | Support **random access** by index (e.g., `array_name[index]`). This allows for direct and very fast access to any element in O(1) time. | Primarily support **sequential access**; elements can only be accessed by traversing the list from the `START` pointer, following each node's `next` pointer. Accessing the Nth element typically takes O(N) time. |
| **Insertion/Deletion** | Generally **inefficient** for operations in the middle (O(n) complexity). Inserting or deleting an element requires shifting subsequent elements to maintain contiguity. | Highly **efficient** for operations (O(1) complexity) if the target node's address (or its predecessor's) is known. It involves simply updating a few pointers rather than shifting data blocks. However, finding the target node itself can be O(n). |
| **Memory Usage (Overhead)** | Lower; primarily stores just the data elements themselves. There's minimal memory overhead per element. | Higher; each node requires additional memory space to store one or more pointers (`next`, and `prev` for doubly linked lists) in addition to its data. This pointer storage is an overhead per node. |
| **Memory Utilization** | Can lead to **memory wastage** if a large array is declared but only a small portion is actually used by the program. | More efficient in memory utilization for dynamic data, as memory is allocated precisely as needed for each new node, reducing wasted space. |

---

## 💻 Types of Linked Lists Implemented:

### 1. Singly Linked List (SLL)

A linear data structure where each node contains data and a pointer to the next node, allowing traversal in only one direction.

* **Node Structure:**
    ```c
    // Defined in singly_linked_list/sll_node_structure.h
    struct Node {
        int data;           // Data stored in the node
        struct Node* next;  // Pointer to the next node in the list
    };
    ```
    The global `start` pointer for the linked list is also declared externally in `sll_node_structure.h`.

* **Implemented Operations and Algorithms:**

    * **`create_ll`**: Initializes and populates the linked list with user-provided data. This involves dynamic memory allocation.
        **Algorithm (Conceptual)**:
        ```
        Step 1: Loop to get user input until a sentinel value (e.g., -1) is entered.
        Step 2:   Allocate memory for NEW_NODE. Handle OVERFLOW if allocation fails.
        Step 3:   Set NEW_NODE->data = user_input.
        Step 4:   Set NEW_NODE->next = NULL.
        Step 5:   If list is empty, NEW_NODE becomes START.
        Step 6:   Else, traverse to the last node and link it to NEW_NODE.
        Step 7: End loop.
        Step 8: Return START.
        ```
        (Code in `singly_linked_list/sll_create_display.c`)

    * **`display`**: Traverses and prints all elements of the linked list.

        **Algorithm for Traversing a Linked List**:
        ```
        Step 1: [INITIALIZE] SET PTR = START
        Step 2: Repeat Steps 3 and 4 while PTR != NULL
        Step 3: Apply Process to PTR->DATA (e.g., print data)
        Step 4: SET PTR = PTR->NEXT
        [END OF LOOP]
        Step 5: EXIT
        ```
        (Code in `singly_linked_list/sll_create_display.c`)

    * **`count_nodes`**: Counts and returns the total number of nodes in the list.

        **Algorithm to Count the Number of Nodes in a Linked List**:
        ```
        Step 1: [INITIALIZE] SET COUNT = 0
        Step 2: [INITIALIZE] SET PTR = START
        Step 3: Repeat Steps 4 and 5 while PTR != NULL
        Step 4: SET COUNT = COUNT + 1
        Step 5: SET PTR = PTR->NEXT
        [END OF LOOP]
        Step 6: Return COUNT
        Step 7: EXIT
        ```
        (Code in `singly_linked_list/sll_create_display.c`)

    * **`insert_beg`**: Inserts a new node at the beginning of the list.

        **Algorithm for Inserting a Node at the Beginning**:
        ```
        Step 1: If memory allocation fails (OVERFLOW), display message and exit.
        Step 2: Allocate memory for NEW_NODE.
        Step 3: Set NEW_NODE->DATA = data_to_insert.
        Step 4: Set NEW_NODE->NEXT = START.
        Step 5: Set START = NEW_NODE.
        Step 6: EXIT.
        ```
        (Code in `singly_linked_list/sll_insert_operations.c`)

    * **`insert_end`**: Inserts a new node at the end of the list.

        **Algorithm for Inserting a Node at the End**:
        ```
        Step 1: If memory allocation fails (OVERFLOW), display message and exit.
        Step 2: Allocate memory for NEW_NODE.
        Step 3: Set NEW_NODE->DATA = data_to_insert.
        Step 4: Set NEW_NODE->NEXT = NULL.
        Step 5: If START is NULL (empty list), set START = NEW_NODE.
        Step 6: Else, traverse PTR from START until PTR->NEXT is NULL.
        Step 7: Set PTR->NEXT = NEW_NODE.
        Step 8: EXIT.
        ```
        (Code in `singly_linked_list/sll_insert_operations.c`)

    * **`insert_before`**: Inserts a new node before a node with a specified value.

        **Algorithm for Inserting a Node Before a Given Node**:
        ```
        Step 1: If memory allocation fails (OVERFLOW), display message and exit.
        Step 2: Allocate memory for NEW_NODE.
        Step 3: Set NEW_NODE->DATA = data_to_insert.
        Step 4: If list is empty or target_value is at START, insert NEW_NODE at beginning.
        Step 5: Else, traverse PTR and PREPTR from START until PTR->DATA = target_value or PTR is NULL.
        Step 6: If target_value is not found, display message.
        Step 7: Else, set PREPTR->NEXT = NEW_NODE and NEW_NODE->NEXT = PTR.
        Step 8: EXIT.
        ```
        (Code in `singly_linked_list/sll_insert_operations.c`)

    * **`insert_after`**: Inserts a new node after a node with a specified value.

        **Algorithm for Inserting a Node After a Given Node**:
        ```
        Step 1: If memory allocation fails (OVERFLOW), display message and exit.
        Step 2: Allocate memory for NEW_NODE.
        Step 3: Set NEW_NODE->DATA = data_to_insert.
        Step 4: Traverse PTR from START until PTR->DATA = target_value or PTR is NULL.
        Step 5: If target_value is not found, display message.
        Step 6: Else, set NEW_NODE->NEXT = PTR->NEXT and PTR->NEXT = NEW_NODE.
        Step 7: EXIT.
        ```
        (Code in `singly_linked_list/sll_insert_operations.c`)

    * **`delete_beg`**: Deletes the node from the beginning of the list.

        **Algorithm for Deleting the First Node**:
        ```
        Step 1: If START is NULL (UNDERFLOW), display message and exit.
        Step 2: Set PTR = START.
        Step 3: Set START = START->NEXT.
        Step 4: FREE PTR.
        Step 5: EXIT.
        ```
        (Code in `singly_linked_list/sll_delete_operations.c`)

    * **`delete_end`**: Deletes the node from the end of the list.

        **Algorithm for Deleting the Last Node**:
        ```
        Step 1: If START is NULL (UNDERFLOW), display message and exit.
        Step 2: If START->NEXT is NULL (only one node), set START = NULL and FREE START.
        Step 3: Else, traverse PTR and PREPTR from START until PTR->NEXT is NULL.
        Step 4: Set PREPTR->NEXT = NULL.
        Step 5: FREE PTR.
        Step 6: EXIT.
        ```
        (Code in `singly_linked_list/sll_delete_operations.c`)

    * **`delete_node`**: Deletes a specific node by its value.

        **Algorithm for Deleting a Specific Node by Value**:
        ```
        Step 1: If START is NULL (UNDERFLOW), display message and exit.
        Step 2: If START->DATA = value_to_delete, then delete the first node.
        Step 3: Else, traverse PTR and PREPTR from START until PTR->DATA = value_to_delete or PTR is NULL.
        Step 4: If value_to_delete is not found, display message.
        Step 5: Else, set PREPTR->NEXT = PTR->NEXT and FREE PTR.
        Step 6: EXIT.
        ```
        (Code in `singly_linked_list/sll_delete_operations.c`)

    * **`delete_after`**: Deletes the node immediately following a node with a specified value.

        **Algorithm for Deleting the Node After a Given Node**:
        ```
        Step 1: If START is NULL (UNDERFLOW), display message and exit.
        Step 2: Traverse PTR from START until PTR->DATA = target_value or PTR is NULL.
        Step 3: If target_value is not found or PTR->NEXT is NULL, display message.
        Step 4: Else, set TEMP = PTR->NEXT.
        Step 5: Set PTR->NEXT = TEMP->NEXT.
        Step 6: FREE TEMP.
        Step 7: EXIT.
        ```
        (Code in `singly_linked_list/sll_delete_operations.c`)

    * **`sort_list`**: Sorts the elements of the list (e.g., using a simple bubble sort logic for linked lists).

        **Algorithm for Sorting a Linked List (Conceptual Bubble Sort)**:
        ```
        Step 1: If list is empty or has one node, return.
        Step 2: Set PTR1 = START.
        Step 3: Loop while PTR1->NEXT != NULL (outer loop for passes).
        Step 4:   Set PTR2 = PTR1->NEXT (inner loop for comparisons).
        Step 5:   Loop while PTR2 != NULL.
        Step 6:     If PTR1->DATA > PTR2->DATA, SWAP PTR1->DATA and PTR2->DATA.
        Step 7:     Set PTR2 = PTR2->NEXT.
        Step 8:   End inner loop.
        Step 9:   Set PTR1 = PTR1->NEXT.
        Step 10: End outer loop.
        Step 11: Return START.
        ```
        (Code in `singly_linked_list/sll_main.c` or a separate utility file if preferred.)

    * **`delete_list`**: Deletes all nodes in the linked list and frees their memory.

        **Algorithm for Deleting the Entire Linked List**:
        ```
        Step 1: Loop while START != NULL.
        Step 2:   Set PTR = START.
        Step 3:   Set START = START->NEXT.
        Step 4:   FREE PTR.
        Step 5: End loop.
        Step 6: EXIT.
        ```
        (Code in `singly_linked_list/sll_main.c` or a separate utility file if preferred.)

---

### **Modular Code Structure:**

The implementation of Singly Linked List operations is modularized into the following files within the `singly_linked_list/` directory:
* [`sll_node_structure.h`](./singly_linked_list/sll_node_structure.h): Contains the `struct Node` definition and external declaration of the global `start` pointer.
* [`sll_create_display.c`](./singly_linked_list/sll_create_display.c): Implements `create_ll`, `display`, and `count_nodes` functions.
* [`sll_insert_operations.c`](./singly_linked_list/sll_insert_operations.c): Implements `insert_beg`, `insert_end`, `insert_before`, and `insert_after` functions.
* [`sll_delete_operations.c`](./singly_linked_list/sll_delete_operations.c): Implements `delete_beg`, `delete_end`, `delete_node`, and `delete_after` functions.
* [`sll_main.c`](./singly_linked_list/sll_main.c): Contains the `main` function, which provides the interactive menu and calls the various operation functions. It also houses `sort_list` and `delete_list` for demonstration purposes.

