#include <stdio.h>

void find_triplets(int arr[], int n) {
    int i, j, k;

    for (i = 0; i < n-2; i++) {
        j = i+1;
        k = n-1;
        while (j < k) {
            if (arr[i] + arr[j] == arr[k]) {
                printf("%d + %d = %d (indices %d, %d, %d)\n", arr[i], arr[j], arr[k], i, j, k);
                j++;
                k--;
            } else if (arr[i] + arr[j] < arr[k]) {
                j++;
            } else {
                k--;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    find_triplets(arr, n);

    return 0;
}