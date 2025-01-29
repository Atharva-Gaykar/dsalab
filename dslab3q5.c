#include <stdio.h>

void selectsortevenidx(int *B, int N)
{

    int L = 0;

    if (N % 2 == 0)
    {

        L = N / 2;
    }
    else
    {

        L = N / 2 + 1;
    }

    int A[L];
    int y = 0;

    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {

            A[y] = B[i];
            y++;
        }
    }

    for (int i = 0; i < L - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < L; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        int te = A[i];
        A[i] = A[min];
        A[min] = te;
    }

    int x = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {

            B[i] = A[x];
            x++;
        }
    }

    printf("even idx sort \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
}
void selectsortoddidx(int *C, int N)
{

    int L = 0;

    if (N % 2 == 0)
    {

        L = N / 2;
    }
    else
    {

        L = N / 2 + 1;
    }

    int A[L];
    int y = 0;

    for (int i = 0; i < N; i++)
    {
        if (i % 2 != 0)
        {

            A[y] = C[i];
            y++;
        }
    }

    for (int i = 0; i < L - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < L; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        int te = A[i];
        A[i] = A[min];
        A[min] = te;
    }

    int x = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 != 0)
        {

            C[i] = A[x];
            x++;
        }
    }

    printf("odd idx sort \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
}

void selectionsort(int *D, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (D[min] > D[j])
            {
                min = j;
            }
        }
        int temp = D[i];
        D[i] = D[min];
        D[min] = temp;
    }

    printf("sorted array \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", D[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);
    
    
    int B[N];
    int C[N];
    int D[N];


    for (int i = 0; i < N; i++)
    {
        printf("Enter element no.%d: ", i);
        scanf("%d", &B[i]);
        C[i] = B[i];
        D[i] = B[i];
    }

    selectsortevenidx(B, N);
    selectsortoddidx(C, N);
    selectionsort(D, N);
    return 0;
}