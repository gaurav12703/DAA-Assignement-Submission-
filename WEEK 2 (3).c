#include <stdio.h>

int countPairsWithDifference(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] - arr[i] == k || arr[i] - arr[j] == k) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int count = countPairsWithDifference(arr, n, k);
    printf("Number of pairs with difference %d: %d\n", k, count);
    return 0;
}