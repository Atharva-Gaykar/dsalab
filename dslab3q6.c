#include <stdio.h>

void insertsortevenidx(int *B, int N)
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

    for (int i = 1; i < L; i++)
    {
        int j = i - 1;
        int temp = A[i];
        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
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
void inserttsortoddidx(int *C, int N)
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

    for (int i = 1; i < L; i++)
    {
        int j = i - 1;
        int temp = A[i];
        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
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

void insertionsort(int *D, int N)
{
    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int temp = D[i];
        while (j >= 0 && D[j] > temp)
        {
            D[j + 1] = D[j];
            j--;
        }
        D[j + 1] = temp;
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

    insertsortevenidx(B, N);
    inserttsortoddidx(C, N);
    insertionsort(D, N);
    return 0;
}