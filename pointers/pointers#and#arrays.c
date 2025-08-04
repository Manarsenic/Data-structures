#include <stdio.h>
// Function that takes an array and its size, and uses a pointer to calculate the sum.
void calculate_sum(int *array_ptr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        // Use pointer arithmetic to access each element
        sum += *(array_ptr + i);
    }
    printf("The sum of the array elements is: %d\n", sum);
}
int main() {
    int my_array[5] = {10, 20, 30, 40, 50};
    int array_size = 5;
    calculate_sum(my_array, array_size);
    int *ptr = my_array;
    printf("First element value via pointer: %d\n", *ptr);
    printf("Third element value via pointer arithmetic: %d\n", *(ptr + 2));
    return 0;
}
