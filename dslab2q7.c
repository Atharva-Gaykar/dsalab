#include<stdio.h>
voidinsertioncount(int N, int *arr2)
{

    int count = 0;

    for (int i = 1; i < N; i++)
    {
        int j = i - 1;
        int temp = arr2[i];

        while (temp < arr2[j] && j >= 0)
        {
            arr2[j] = arr2[j + 1];
            j--;
        }
        arr2[j + 1] = temp;
        count++;
    }

    printf("the number of insertions are  %d ", count);
    printf("\n");
}

int main(){

   int N;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    int arr[N];
    

    for (int i = 0; i < N; i++)
    {
        printf("Enter element no.%d: ", i);
        scanf("%d", &arr[i]);
        
        
    }

    
    insertioncount( N, arr);

    return 0;
}