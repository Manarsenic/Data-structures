#include <stdio.h>

// The Interpolation Search function
int interpolation_search(int a[], int low, int high, int val) {
    int mid;
    while (low <= high && val >= a[low] && val <= a[high]) {
        // Calculate the 'mid' position based on interpolation formula
        mid = low + (((double)(high - low) / (a[high] - a[low])) * (val - a[low]));

        if (a[mid] == val) {
            return mid;
        }
        if (a[mid] < val) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 70;
    int result = interpolation_search(arr, 0, n - 1, key);
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}
