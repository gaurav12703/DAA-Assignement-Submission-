#include <stdio.h>

void insertion_sort(int arr[], int n, int *comp, int *shift) {
    int i, key, j;
    *comp = 0;
    *shift = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        (*comp)++;
        while (j >= 0 && arr[j] > key) {
            (*comp)++;
            arr[j + 1] = arr[j];
            (*shift)++;
            j = j - 1;
        }
        arr[j + 1] = key;
        (*shift)++;
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int comp, shift;
    insertion_sort(arr, n, &comp, &shift);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nNumber of comparisons: %d\n", comp);
    printf("Number of shifts: %d\n", shift);
    return 0;
}