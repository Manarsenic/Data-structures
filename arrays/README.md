# 📘 Arrays in C

Arrays in C are a collection of elements of the same data type stored in contiguous memory locations. They provide a way to group related data together, making it easier to manage and manipulate.

---

##  Key Concepts

- **Declaration**: `int arr[10];` declares an integer array of size 10.
- **Indexing**: Array elements are accessed using indices starting from 0.
- **Initialization**: Arrays can be initialized at declaration, e.g., `int arr[3] = {1, 2, 3};`
- **Memory Layout**: Elements are stored in consecutive memory blocks.
- **Access**: Access is constant time: `O(1)`.

---

## Types of Arrays

### 1. **One-Dimensional Arrays**
Used for linear data storage like lists.

```c
#include <stdio.h>
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}





#include <stdio.h>
int main() {
    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}


3. Multidimensional Arrays
Can go beyond 2D for complex data structures, though less common.

⚙️ Common Array Operations
Traversal: Loop through all elements

Insertion: Add at a specific index (shifting required)

Deletion: Remove an element (shift left)

Search: Linear or Binary (if sorted)

Update: Change element at a specific index



Example: Searching in an Array (Linear Search)



#include <stdio.h>
int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int key = 20, found = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found.\n");
    return 0;
}



 Two-Dimensional Arrays and Pointers
c
Copy code
int mat[5][5];
int **ptr;
int **ptr; is not the same as int mat[5][5];

mat[i][j] is equivalent to:

*(*(mat + i) + j)

*(mat[i] + j)

Pointer arithmetic in 2D:

int (*ptr)[10]; — pointer to an array of 10 integers.

int *ptr[10]; — array of 10 pointers to int



POINTER TO A 2D ARRAY

#include <stdio.h>
int main() {
    int arr[2][2] = {{1, 2}, {3, 4}};
    int i, j, (*parr)[2];
    parr = arr;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            printf(" %d", (*(parr + i))[j]);
    }
    return 0;
}


Passing Arrays to Functions
1D Arrays: passed as int arr[] or int *arr

2D Arrays: must specify column size int arr[][COLS]


#include <stdio.h>
void display(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
int main() {
    int data[] = {1, 2, 3, 4, 5};
    display(data, 5);
    return 0;
}




 Sparse Matrices
Used when most elements in a 2D array are 0 to save memory.

✅ Features:
Stores only non-zero values with their row & column index.

Useful for graphs, matrices in machine learning, etc.

c
Copy code
#include <stdio.h>
#define SIZE 4

int main() {
    int sparse[SIZE][SIZE] = {
        {0, 0, 3, 0},
        {0, 0, 0, 0},
        {5, 0, 0, 0},
        {0, 2, 0, 0}
    };

    printf("Row Col Value\n");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (sparse[i][j] != 0)
                printf("%3d %3d %5d\n", i, j, sparse[i][j]);

    return 0;
}
