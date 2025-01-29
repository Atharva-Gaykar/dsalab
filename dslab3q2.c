#include <stdio.h>
void replaceproduct(int N, int B[][3])
{

    int A[N][N];
    int pro[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
            pro[i][j] = 0;
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
    int cl = 0;
    for (int row = 1; row <= N - 2; row++)
    {

        int tempa[3] = {row - 1, row, row + 1};

        for (int col = 1; col <= N - 2; col++)
        {

            for (int i = 0; i < 3; i++)
            {

                int t = tempa[i];

                for (int j = col - 1; j <= col + 1; j++)
                {
                    int pro1 = A[t][j] * B[i][cl];
                    pro[t][j] = pro1;
                    cl++;
                }
                cl = 0;
            }
        }
    }
    
    printf("Window matrix after replacing the element with the product: \n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", pro[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int N;
    printf("Enter the row and column of big square matrix: ");
    scanf("%d", &N);
    int B[3][3];
    printf("Enter the 9 elements of the matrix B: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("B[%d][%d]: ", i + 1, j + 1);

            scanf("%d", &B[i][j]);
        }
    }

    replaceproduct(N, B);
    return 0;
}