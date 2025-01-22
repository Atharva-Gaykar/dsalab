#include <stdio.h>

void maxfind(int *A, int N, int K)
{
    int temp[N];
    int max = 0, y = 0;
    int midx = 0;
    int mint = A[0];

    for (int i = 1; i < N; i++)
    {
        if (mint > A[i])
        {
            mint = A[i];
        }
    }

    printf("mint %d\n", mint);

    if (K == N)
    {
        printf("the kth largest element is %d\n", mint);
        return;
    }

    for (int p = 1; p <= K; p++)
    {
       
        if (p == 1)
        {
            max = mint;

            for (int i = 0; i < N; i++)
            {
                if (A[i] > max)
                {
                    max = A[i];
                    midx = i;
                }
            }

          
            temp[y] = midx;
            y++;
        }

        if (p != 1)
        {
            max = mint;
            int flag = 0;
            for (int i = 0; i < N; i++)
            {
                flag = 0;

                for (int j = 0; j < y; j++)
                {
                    if (i == temp[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 1)
                {
                    continue;
                }

                if (A[i] > max)
                {
                    max = A[i];
                    midx = i;
                }
            }

            
            temp[y] = midx;
            y++;
        }
    }

    printf("the kth largest num %d", max);
}

int main()
{
    int N;
    printf("the number of elements\n");
    scanf("%d", &N);

    int A[N];

    printf("enter the elements\n");
    for (int i = 0; i < N; i++)
    {
        printf("element no. %d\n", i + 1);
        scanf("%d", &A[i]);
    }

    int K;

    printf("enter K\n");
    scanf("%d", &K);

    maxfind(A, N, K);

    return 0;
}
