#include <stdio.h>



void movingavg(int N, float *arr, int K) 
{
    if (N > K)
    {
        int st = 0;
        int ed = st;
        float sum = 0;
        float sum1=0;
        int str=0;

        while (str<N)
        {
           
           sum1+=arr[str];
           printf("%.2f ", sum1 / K);
           str++;

            
        }
        printf(" ");
        

        while (ed <= N-2) 
        {
            if (ed != st + K - 1)
            {
                sum = sum + arr[ed];
                ed++;
            }
            if (ed == st + K - 1)
            {
                sum = sum + arr[ed];
                printf("%.2f ", sum / K); 
                sum = 0;
                st++;
                ed = st;
            }
        }
    }
}

int main()
{
    int N, K; 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    float arr[N];
    printf("Enter the elements of the array: ");

    for (int i = 0; i < N; i++)  
    {
        scanf("%f", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &K); 

    movingavg(N, arr, K);

    return 0;
}
