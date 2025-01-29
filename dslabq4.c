#include <stdio.h>

void selectsort(int *B, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < 9; j++)
        {
            if (B[j] < B[min])
            {
                min = j;
            }
        }
        int te = B[i];
        B[i] = B[min];
        B[min] = te;
    }
}
void insertion(int *A, int N)
{

    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int key = A[i];
        while (A[j] >= key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{

    int N;
    int B[N];
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    return 0;
}