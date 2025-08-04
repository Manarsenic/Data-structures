#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *ptr = arr; // ptr points to the first elemen arr[0]

    printf("Value of the first element: %d",*ptr);

    ptr++; // Incrementer
    printf("Value of the second element (after increment): %d\n", *ptr);

    return 0;
}
