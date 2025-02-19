#include <stdio.h>
#include <stdlib.h>

int partition(int* arr, int st, int ed) {
    int idx = st - 1;
    int pivot = arr[ed];
    int j = st;

    while (j <= ed - 1) {
        if (arr[j] <= pivot) {
            idx++;
            int temp = arr[idx];
            arr[idx] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    idx++;
    int temp = arr[idx];
    arr[idx] = arr[ed];
    arr[ed] = temp;

    return idx;
}

void quicksort(int *arr, int st, int ed) {
    if (st < ed) {
        int pivot = partition(arr, st, ed);
        quicksort(arr, st, pivot - 1);
        quicksort(arr, pivot + 1, ed);
    }
}

int main() {
   
    int n ; 

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];

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
