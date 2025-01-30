#include <stdio.h>

void combinesort(int *A, int st, int mid, int ed)
{

    int i, j;
    i = st;
    j = mid + 1;
    int y = 0;
    int temp[ed - st + 1];

    while (i <= mid && j <= ed)
    {
        if (A[i] <= A[j])
        {
            temp[y] = A[i];
            y++;
            i++;
        }
        else
        {
            temp[y] = A[j];
            y++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[y] = A[i];
        y++;
        i++;
    }
    while (j <= ed)
    {
        temp[y] = A[j];
        y++;
        j++;
    }

    for (int idx = 0; idx < ed - mid + 1; idx++)
    {
        A[idx + st] = temp[idx];
    }
}

void mergesort(int *A, int st, int ed)
{
    if (st < ed)
    {
        int mid = st + (ed - st) / 2;

        mergesort(A, st, mid);
        mergesort(A, mid + 1, ed);
        combinesort(A, st, mid, ed);
    }
}
int main()
{

    int N;
    printf("Enter the number of elements in array: ");
    scanf("%d", &N);
    int A[N];

    printf("Enter the elements of array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    mergesort(A, 0, N - 1);

    printf("Sorted array is:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}