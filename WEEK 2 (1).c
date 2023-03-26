#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x);

int main() {
    int n, key, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("%d is not present in the array.", key);
    } else {
        int count = 1;
        i = result - 1;
        while (i >= 0 && arr[i] == key) {
            count++;
            i--;
        }
        i = result + 1;
        while (i < n && arr[i] == key) {
            count++;
            i++;
        }
        printf("%d is present in the array %d times.", key, count);
    }
    return 0;
}

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}