#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (high < low) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, high, key);
    }
}

int searchInArray(int arr[], int n, int key) {
    int i = 0;
    while (i < n && arr[i] <= key) {
        if (arr[i] == key) {
            return i;
        }
        i += 2;
    }
    return binarySearch(arr, i / 2, i, key);
}
