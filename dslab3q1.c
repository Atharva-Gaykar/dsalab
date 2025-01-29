#include <stdio.h>

void replace(int N)
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
        int temp[3];
        int temp[3] = {row - 1, row, row + 1};

        for (int col = 1; col <= N - 2; col++)
        {

            int sum = 0;

            for (int i = 0; i < 3; i++)
            {

                int t = temp[i];
                int l=0;
                

                for (int j = col - 1; j <= col + 1; j++)
                {

                    sum += A[t][j];
                }
            }
            A[row][col] = sum / 9;
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
    printf("Enter the row and column of big square matrix: ");
    scanf("%d", &N);

    replace(N);

    return 0;
}