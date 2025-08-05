# 📘 Arrays in C

Arrays in C are a collection of elements of the same data type stored in contiguous memory locations. They provide a way to group related data together, making it easier to manage and manipulate.

---

### Key Concepts

- **Declaration**: `int arr[10];` declares an integer array of size 10.
- **Indexing**: Array elements are accessed using indices starting from 0.
- **Initialization**: Arrays can be initialized at declaration, e.g., `int arr[3] = {1, 2, 3};`.
- **Memory Layout**: Elements are stored in consecutive memory blocks.
- **Access**: Accessing any element is a constant time operation: `O(1)`.

---

### 📚 Types of Arrays

- **One-Dimensional Arrays**: Used for linear data storage like lists.
- **Two-Dimensional Arrays**: Used to represent tables or grids.
- **Multidimensional Arrays**: Can go beyond 2D for complex data structures, though less common.

---

### ⚙️ Common Array Operations

- **Traversal**: Looping through all elements.
- **Insertion**: Adding an element at a specific index (requires shifting).
- **Deletion**: Removing an element (requires shifting).
- **Search**: Finding an element (e.g., using Linear or Binary search).
- **Update**: Changing an element at a specific index.

---

### 💡 Pointers and Arrays

- In C, an array name can be used as a pointer to its first element.
- This allows you to access array elements using pointer arithmetic.
- The expression `mat[i][j]` is equivalent to pointer expressions like `*(*(mat + i) + j)` and `*(mat[i] + j)`.

---

### 📂 Implemented Code Examples

The code examples for these concepts and operations are organized in the `arrays` folder.

- **One-Dimensional Arrays**: Basic declaration and looping.
- **Two-Dimensional Arrays**: Basic declaration and nested looping.
- **Linear Search**: A basic search operation.
- **Pointers and 2D Arrays**: Demonstrates pointer arithmetic on a 2D array.
- **Passing Arrays to Functions**: A function that accepts a 1D array.
- **Sparse Matrices**: An example of storing a sparse matrix and printing its non-zero elements.
