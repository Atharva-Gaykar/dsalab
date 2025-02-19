#include <stdio.h>
#include <stdlib.h>

int partition(int*arr, int st, int ed) {
    int pivot = arr[st];
    int i = st + 1;
    int j = ed;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[st];
    arr[st] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int *arr, int st, int ed) {
    if (st < ed) {
        int pivot = partition(arr, st, ed);
        quicksort(arr, st, pivot - 1);
        quicksort(arr, pivot + 1, ed);
    }
}

int main() {
    int arr[10];
    int n = 10;

    printf("Enter 10 elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
