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

    for (int i = 0; i < y; i++)
    {
        printf("the unique elements are %d", unq[i]);
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
