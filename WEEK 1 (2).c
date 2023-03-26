#include <stdio.h>

int binary_search(int arr[], int n, int key, int *count) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        (*count)++;
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            return 1; 
        } else if (arr[mid] < key) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }
    return 0; 
}

int main() {
    int arr[] = {1, 3, 4, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int count = 0;

    if (binary_search(arr, n, key, &count)) {
        printf("%d is present in the array.\n", key);
    } else {
        printf("%d is not present in the array.\n", key);
    }
    printf("Number of comparisons made: %d\n", count);

    return 0;
}