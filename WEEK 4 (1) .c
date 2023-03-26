#include <stdio.h>

void merge(int arr[], int left[], int leftSize, int right[], int rightSize, int *comparisons, int *inversions) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            *inversions += leftSize - i;
        }
        *comparisons += 1;
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n, int *comparisons, int *inversions) {
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    int left[mid], right[n - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid, comparisons, inversions);
    mergeSort(right, n - mid, comparisons, inversions);
    merge(arr, left, mid, right, n - mid, comparisons, inversions);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int comparisons = 0, inversions = 0;
    mergeSort(arr, n, &comparisons, &inversions);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons: %d\n", comparisons);
    printf("Number of inversions: %d\n", inversions);
    return 0;
}
