#include <stdio.h>

void sortcount(int N, int *arr)
{
    int count = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    printf("the number of swaps: %d\n", count);
}

void selectioncount(int N, int *A)
{

    int count = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < count; j++)
        {
            if (A[min] > A[j])
            {
                min = j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
        count++;
    }
}

int main()
{

    int N;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    int arr[N];

    int A[N];

    for (int i = 0; i < N; i++)
    {
        printf("Enter element no.%d: ", i);
        scanf("%d", &arr[i]);

        A[i] = arr[i];
    }

    selectioncount(N, A);
    sortcount(N, arr);

    return 0;
}
