# 🔍 Sorting and Searching Algorithms in C

A collection of classic sorting and searching techniques implemented in the C language. Each file includes the algorithm and a simple example to demonstrate its working.

---

## 📦 Implemented Algorithms

### 🟢 Radix Sort [`radix_sort.c`]
> Radix Sort is a non-comparative algorithm that processes integers digit by digit, starting from the least significant digit. It uses a stable sort (e.g., counting sort) internally.

- 📌 **Use Case:** Sorting integers with similar digit lengths
- ⚙️ **Time Complexity:** O(nk)
- 💾 **Space Complexity:** O(n + k)
- ✅ **Stable:** Yes  
- 🧠 **Commit:** `feat: add radix sort implementation`

---

### 🔵 Heap Sort [`heap_sort.c`]
> Heap Sort uses a binary heap to sort elements by first building a max heap and then repeatedly removing the largest element.

- 📌 **Use Case:** Efficient, in-place sort without recursion
- ⚙️ **Time Complexity:** O(n log n)
- 💾 **Space Complexity:** O(1)
- ❌ **Stable:** No  
- 🧠 **Commit:** `feat: add heap sort implementation`

---

### 🟣 Interpolation Search [`interpolation_search.c`]
> An advanced form of binary search that works best on uniformly distributed sorted arrays. It estimates the likely position of the target value.

- 📌 **Use Case:** Efficient search for evenly spaced data
- ⚙️ **Best/Average Case:** O(log log n)
- 🚨 **Worst Case:** O(n)
- 🧠 **Commit:** `feat: add interpolation search implementation`

---

## 🚀 How to Run

Use any C compiler like `gcc` to compile and run these programs:

```bash
gcc radix_sort.c -o radix
./radix

gcc heap_sort.c -o heap
./heap

gcc interpolation_search.c -o search
./search

