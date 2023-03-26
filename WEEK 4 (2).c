 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high, int *comp, int *swap) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            (*comp)++;
            i++;
        }

        while (j >= low && arr[j] > pivot) {
            (*comp)++;
            j--;
        }

        if (i < j) {
            (*swap)++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    (*swap)++;
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int low, int high, int *comp, int *swap) {
    if (low < high) {
        int pivot_index = low + rand() % (high - low + 1);
        (*swap)++;
        int temp = arr[low];
        arr[low] = arr[pivot_index];
        arr[pivot_index] = temp;

        int partition_index = partition(arr, low, high, comp, swap);

        quicksort(arr, low, partition_index - 1, comp, swap);
        quicksort(arr, partition_index + 1, high, comp, swap);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    int comp = 0, swap = 0;
    quicksort(arr, 0, n - 1, &comp, &swap);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Number of comparisons: %d\n", comp);
    printf("Number of swaps: %d\n", swap);

    return 0;
}