 #include <stdio.h>

int linear_search(int arr[], int n, int key, int *count) {
    for (int i = 0; i < n; i++) {
        (*count)++;
        if (arr[i] == key) {
            return 1;
        }
    }
    return 0; 
}

int main() {
    int arr[] = {3, 5, 1, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    int count = 0;

    if (linear_search(arr, n, key, &count)) {
        printf("%d is present in the array.\n", key);
    } else {
        printf("%d is not present in the array.\n", key);
    }
    printf("Number of comparisons made: %d\n", count);

    return 0;
}