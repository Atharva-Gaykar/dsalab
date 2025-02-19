#include <stdio.h>

void Bubble_sort(int *A, int N)
{
    int flag2 = 0;
    for (int idx = 0; idx < N - 1; idx++)
    {
        if (A[idx + 1] < A[idx])
        {
            flag2 = 1;
        }
    }

    if (flag2 == 1)
    {
        int flag = 0;
        for (int i = 0; i < N - 1; i++)
        {

            for (int j = 0; j < N - i - 1; j++)
            {
                if (A[j] > A[j + 1])
                {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
            flag = 0;

            for (int idx = 0; idx < N - 1; idx++)
            {
                if (A[idx + 1] < A[idx])
                {
                    flag = 1;
                }
            }

            if (flag == 0)
            {
                break;
            }

            printf("pass %d\n", i + 1);
        }

        for (int i = 0; i < N; i++)
        {
            printf("%d ", A[i]);
        }
    }

    else
    {
        printf("array is already sorted\n");

        for (int i = 0; i < N; i++)
        {
            printf("%d ", A[i]);
        }
    }
}

int main()
{
    int N;

    printf("enter the number of elements ");
    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++)
    {
        printf("element no.%d ", i + 1);
        scanf("%d", &A[i]);
    }

    Bubble_sort(A, N);

    return 0;
}
