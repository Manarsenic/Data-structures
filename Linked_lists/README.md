
# Linked Lists in C

This directory contains C implementations of various types of linked lists, which are fundamental dynamic data structures. The concepts and operational principles presented here reflect my understanding and learning, significantly shaped by comprehensive study resources on Data Structures.

## 📚 Introduction to Linked Lists and Their Fundamental Use

[cite_start]A linked list is a linear collection of data elements, which are commonly referred to as **nodes**[cite: 707]. [cite_start]It is a very flexible, dynamic data structure in which elements (nodes) form a sequential list[cite: 707]. [cite_start]Unlike static arrays, a programmer need not worry about the maximum number of elements that will be stored in the linked list[cite: 707]. This characteristic allows developers to write robust programs that can adapt to varying data quantities without worrying about memory limitations.

### Basic Terminologies

* [cite_start]**Node**: Each individual element within a linked list[cite: 707].
* [cite_start]**Data Field**: One part of a node that stores the actual information or value[cite: 708]. [cite_start]This can be a simple data type, an array, or even a `struct`[cite: 1343].
* [cite_start]**Next Pointer/Link**: The second part of a node that stores the memory address (or a reference/link) to the subsequent node in the sequence[cite: 708]. This pointer is what connects the nodes to form a chain.
* [cite_start]**`NULL` (or X / -1)**: A special value stored in the `next` field of the last node in a list to signify the end or tail of the list[cite: 709, 1343].
* [cite_start]**`START` Pointer**: A primary pointer variable that stores the memory address of the very first node in the entire linked list[cite: 1343]. [cite_start]If `START` is `NULL`, the linked list is empty[cite: 1343].
* [cite_start]**Self-Referential Data Type**: A node in a linked list is considered self-referential because its structure definition includes a pointer type that points back to itself (i.e., a pointer to another node of the same structure type)[cite: 1343].

### Why Use Linked Lists?

Linked lists are indispensable in programming because they address several limitations inherent in static arrays:
* [cite_start]**Dynamic Size**: One of their foremost advantages is the ability to grow or shrink in size during the program's execution, adapting dynamically to the amount of data[cite: 707, 1342]. [cite_start]This eliminates the need to pre-define a fixed maximum capacity[cite: 1342].
* [cite_start]**Efficient Insertion and Deletion**: Unlike arrays, where insertions and deletions often require shifting numerous elements (a time-consuming O(n) operation), linked lists facilitate these operations efficiently[cite: 1342]. [cite_start]By simply modifying a few pointers, insertions and deletions can often be achieved in constant time (O(1)), provided the location for modification is known[cite: 1342].
* [cite_start]**Non-Contiguous Memory Allocation**: Nodes in a linked list do not need to be stored in contiguous memory blocks[cite: 1342]. This flexibility allows memory to be utilized more efficiently, especially in scenarios where large, continuous blocks are scarce.
* [cite_start]**Foundation for Other Structures**: They serve as fundamental building blocks for implementing more intricate data structures, such as various types of stacks, queues, hash tables (via chaining), and certain tree and graph representations[cite: 1343].

## 🆚 Comparison: Linked Lists versus Arrays

[cite_start]While both arrays and linked lists are fundamental linear data structures designed to store collections of data, their internal mechanisms and optimal use cases differ significantly[cite: 1342]:

| Feature                   | Arrays                                                                                                                                                                                                                                                                                                                                                                                                                                                            | Linked Lists                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| :------------------------ | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Memory Allocation** | [cite_start]Elements are stored in **contiguous (adjacent)** memory locations[cite: 702, 1342]. The entire block of memory is typically allocated as a single unit at compile-time or program initialization. | [cite_start]Nodes are **not necessarily stored in consecutive** memory locations[cite: 1342]. [cite_start]Memory for each node is dynamically allocated individually at runtime, often from the heap, and linked together via pointers[cite: 707]. |
| **Size Limitation** | [cite_start]Have a **fixed size**; the maximum number of elements must be declared upfront and cannot be easily changed[cite: 706, 1342]. Resizing an array (if supported by the language) typically involves creating a new, larger array and copying all elements. | [cite_start]Possess a **dynamic size**; the number of elements can easily grow or shrink during the program's execution[cite: 707, 1342]. This adaptability is limited only by the available system memory. |
| **Data Access** | [cite_start]Support **random access** by index (e.g., `array_name[index]`)[cite: 1042, 1310]. [cite_start]This allows for direct and very fast access to any element in O(1) time[cite: 465]. | [cite_start]Primarily support **sequential access**; elements can only be accessed by traversing the list from the `START` pointer, following each node's `next` pointer[cite: 1342]. [cite_start]Accessing the Nth element typically takes O(N) time[cite: 1310]. |
| **Insertion/Deletion** | [cite_start]Generally **inefficient** for operations in the middle (O(n) complexity)[cite: 706]. [cite_start]Inserting or deleting an element requires shifting subsequent elements to maintain contiguity[cite: 706]. | [cite_start]Highly **efficient** for operations (O(1) complexity) if the target node's address (or its predecessor's) is known[cite: 1342]. [cite_start]This involves simply updating a few pointers rather than shifting data blocks[cite: 1342]. However, finding the target node itself can be O(n). |
| **Memory Usage (Overhead)** | [cite_start]Lower; primarily stores just the data elements themselves[cite: 1342]. There's minimal memory overhead per element. | [cite_start]Higher; each node requires additional memory space to store one or more pointers (`next`, and `prev` for doubly linked lists) in addition to its data[cite: 1342]. This pointer storage is an overhead per node. |
| **Memory Utilization** | [cite_start]Can lead to **memory wastage** if a large array is declared but only a small portion is actually used by the program[cite: 1545]. | [cite_start]More efficient in memory utilization for dynamic data, as memory is allocated precisely as needed for each new node, reducing wasted space[cite: 1545]. |

---

## 💻 Types of Linked Lists Implemented:

### 1. Singly Linked List (SLL)

[cite_start]A linear data structure where each node contains data and a pointer to the next node, allowing traversal in only one direction[cite: 1346].

* **Node Structure:**
    ```c
    // From singly_linked_list.c
    struct Node {
        int data;           // Data stored in the node
        struct Node* next;  // Pointer to the next node in the list
    };
    ```

* **Core Operations Implemented:**

    * **`create_ll(struct Node* start)`**: Initializes and populates the linked list with user-provided data. [cite_start]This involves dynamic memory allocation[cite: 1390].
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

    * **`display(struct Node* start)`**: Traverses and prints all elements of the linked list. [cite_start]This aligns with the "Traversing a Linked List" algorithm[cite: 1347].

        **Algorithm for Traversing a Linked List**:
        ```
        Step 1: [INITIALIZE] SET PTR = START
        Step 2: Repeat Steps 3 and 4 while PTR != NULL
        Step 3: Apply Process to PTR->DATA (e.g., print data)
        Step 4: SET PTR = PTR->NEXT
        [END OF LOOP]
        Step 5: EXIT
        ```

    * **`count_nodes(struct Node* start)`**: Counts and returns the total number of nodes in the list. [cite_start]This reflects an adaptation of the algorithm to print the number of nodes[cite: 1347].

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

    * [cite_start]**`insert_beg(struct Node* start)`**: Inserts a new node at the beginning of the list[cite: 1347].

        **Algorithm for Inserting a Node at the Beginning**:
        ```
        Step 1: If memory allocation fails (OVERFLOW), display message and exit.
        Step 2: Allocate memory for NEW_NODE.
        Step 3: Set NEW_NODE->DATA = data_to_insert.
        Step 4: Set NEW_NODE->NEXT = START.
        Step 5: Set START = NEW_NODE.
        Step 6: EXIT.
        ```

    * [cite_start]**`insert_end(struct Node* start)`**: Inserts a new node at the end of the list[cite: 1348].

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

    * **`insert_before(struct Node* start)`**: Inserts a new node before a node with a specified value.

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

    * [cite_start]**`insert_after(struct Node* start)`**: Inserts a new node after a node with a specified value[cite: 1352].

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

    * [cite_start]**`delete_beg(struct Node* start)`**: Deletes the node from the beginning of the list[cite: 1350].

        **Algorithm for Deleting the First Node**:
        ```
        Step 1: If START is NULL (UNDERFLOW), display message and exit.
        Step 2: Set PTR = START.
        Step 3: Set START = START->NEXT.
        Step 4: FREE PTR.
        Step 5: EXIT.
        ```

    * [cite_start]**`delete_end(struct Node* start)`**: Deletes the node from the end of the list[cite: 1350].

        **Algorithm for Deleting the Last Node**:
        ```
        Step 1: If START is NULL (UNDERFLOW), display message and exit.
        Step 2: If START->NEXT is NULL (only one node), set START = NULL and FREE START.
        Step 3: Else, traverse PTR and PREPTR from START until PTR->NEXT is NULL.
        Step 4: Set PREPTR->NEXT = NULL.
        Step 5: FREE PTR.
        Step 6: EXIT.
        ```

    * **`delete_node(struct Node* start, int val)`**: Deletes a specific node by its value.

        **Algorithm for Deleting a Specific Node by Value**:
        ```
        Step 1: If START is NULL (UNDERFLOW), display message and exit.
        Step 2: If START->DATA = value_to_delete, then delete the first node (similar to delete_beg).
        Step 3: Else, traverse PTR and PREPTR from START until PTR->DATA = value_to_delete or PTR is NULL.
        Step 4: If value_to_delete is not found, display message.
        Step 5: Else, set PREPTR->NEXT = PTR->NEXT and FREE PTR.
        Step 6: EXIT.
        ```

    * [cite_start]**`delete_after(struct Node* start, int val)`**: Deletes the node immediately following a node with a specified value[cite: 1351].

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

    * [cite_start]**`sort_list(struct Node* start)`**: Sorts the elements of the list (e.g., using a simple bubble sort logic for linked lists, as seen in common data structure examples)[cite: 1393].

        **Algorithm for Sorting a Linked List (Conceptual Bubble Sort)**:
        ```
        Step 1: If list is empty or has only one node, return (already sorted).
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

    * **`delete_list(struct Node* start)`**: Deletes all nodes in the linked list and frees their memory.

        **Algorithm for Deleting the Entire Linked List**:
        ```
        Step 1: Loop while START != NULL.
        Step 2:   Set PTR = START.
        Step 3:   Set START = START->NEXT.
        Step 4:   FREE PTR.
        Step 5: End loop.
        Step 6: EXIT.
        ```

---

### **Upcoming Implementations:**

These sections represent future developments and will be expanded upon as their respective C implementations are completed and added to this directory.

### 2. Doubly Linked List (DLL)

* **Status**: Implementation planned and will be available soon.

### 3. Circular Linked List (CLL)

* **Status**: Implementation planned and will be available soon.

### 4. Circular Doubly Linked List (CDLL)

* **Status**: Implementation planned and will be available soon.

### 5. Header Linked List

* **Status**: Implementation planned and will be available soon.

### 6. Multi-linked Lists

* **Status**: Conceptual overview and potential implementation details will be added as this advanced topic is explored.
