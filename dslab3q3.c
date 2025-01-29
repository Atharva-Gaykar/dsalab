#include <stdio.h>
void replacemedian(int N)
{

    int A[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (int row = 1; row <= N - 2; row++)
    {
        
        int temp[3] = {row - 1, row, row + 1};

        for (int col = 1; col <= N - 2; col++)
        {

            int B[9];
            int it = 0;

            for (int i = 0; i < 3; i++)
            {

                int t = temp[i];

                for (int j = col - 1; j <= col + 1; j++)
                {

                    B[it] = A[t][j];
                    it++;
                }
            }
            for (int i = 0; i < it - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < 9; j++)
                {
                    if (B[j] < B[min])
                        min = j;
                }
                int te = B[i];
                B[i] = B[min];
                B[min] = te;
            }

            int median = B[4];
            A[row][col] = median;
        }
    }

    printf("Window matrix after replacing the element with the average: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return;
}
int main()
{
    int N;
    printf("Enter the row and column of big: ");
    scanf("%d", &N);

    replacemedian(N);

    return 0;
}