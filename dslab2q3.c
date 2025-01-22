#include <stdio.h>

void countfreq(int N, int *arr)
{

    int flag = 0;
    int y = 0;
    int unq[N];

    int freq[N];
    for (int i = 0; i < N; i++)
    {
        flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            continue;
        }

        int count = 0;
        for (int k = 0; k < N; k++)
        {
            if (arr[i] == arr[k])
            {
                count++;
            }
        }
        unq[y] = arr[i];
        freq[y] = count;
        y++;
    }

    int temp[y];

    for (int i = 0; i < y; i++)
    {
        temp[i] = freq[i];
    }

    for (int i = 0; i < y - 1; i++)
    {
        for (int j = 0; j < y - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    int idx = 0;
    int B[y];
    int ans[y];
    int l = 0;
    
    for (int i = 0; i < y; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < y; j++)
            {
                if (temp[i] == freq[j])
                {

                    idx = j;
                }
            }
            ans[l] = unq[idx];
            B[l]=idx;
            l++;
        }
        else
        {
            
            for (int j = 0; j < y; j++)
            {   
                if (temp[i] == freq[j] && j!=B[l-1])
                {

                    idx = j;
                    break;
                    
                }
            }
            ans[l] = unq[idx];
            B[l]=idx;
            l++;

            
        }
        



    }

    for (int i = 0; i < l; i++)
    {
        printf("%d ", ans[i]);
    }
    
}

int main()
{
    int N;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < N; i++)
    {
        printf("element no.<%d> ", i);
        scanf("%d", &arr[i]);
    }

    countfreq(N, arr);
    return 0;
}
