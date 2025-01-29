#include <stdio.h>


int pivotCount = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pivot = partition(A, low, high);
        pivotCount++; 
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return i + 1;
}

int main() {
    int N;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++) {
        printf("Enter element no.%d: ", i);
        scanf("%d", &A[i]);
    }

    quickSort(A, 0, N - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Number of pivots selected: %d\n", pivotCount);
    return 0;
}
