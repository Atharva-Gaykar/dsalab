#include <stdio.h>

void insert(int N, int *arr)
{
    int A[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        if (i != N)
        {
            A[i] = arr[i];
        }
        else
        {
            A[i] = 0;
        }
    }

    int idx;
    printf("enter the index of the element to be inserted: ");
    scanf("%d", &idx);

    int el;
    printf("enter the element to be inserted: ");
    scanf("%d", &el);

    for (int i = N; i >= idx + 1; i--)
    {
        int temp = A[i];
        A[i] = A[i - 1];
        A[i - 1] = temp;
    }

    A[idx] = el;

    for (int i = 0; i < N + 1; i++)
    {
        printf("%d ", A[i]);
    }
}

void traverse(int *arr, int N)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sort(int *arr, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void reverse(int N, int *arr)
{

    int st = 0;
    int ed = N - 1;

    if (N % 2 == 0)
    {
        while (st <= ed)
        {
            arr[st] = arr[ed];
            st++;
            ed--;
        }
    }
    else
    {
        while (st < ed)
        {
            arr[st] = arr[ed];
            st++;
            ed--;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void evenelsort(int N, int *arr)
{
    int tempidx[N], idx = 0;
    int tempel[N];

    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0)
        {
            tempel[idx] = arr[i];
            tempidx[idx] = i;
            idx++;
        }
    }

    for (int i = 0; i < idx - 1; i++)
    {
        int y = i + 1;

        while (tempel[y - 1] > tempel[y] && y >= 1)
        {
            int temp = tempel[y];
            tempel[y] = tempel[y - 1];
            tempel[y - 1] = temp;

            y--;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        arr[tempidx[i]] = tempel[i];
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void oddelsort(int N, int *arr)
{
    int tempidx[N], idx = 0;
    int tempel[N];

    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 2 != 0)
        {
            tempel[idx] = arr[i];
            tempidx[idx] = i;
            idx++;
        }
    }

    for (int i = 0; i < idx - 1; i++)
    {
        int y = i + 1;

        while (tempel[y - 1] > tempel[y] && y >= 1)
        {
            int temp = tempel[y];
            tempel[y] = tempel[y - 1];
            tempel[y - 1] = temp;

            y--;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        arr[tempidx[i]] = tempel[i];
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sortevenidx(int N, int *arr)
{
    int y = 0, tsz = 0;

    if (N % 2 == 0)
    {
        tsz = N / 2;
    }
    else
    {
        tsz = (N + 1) / 2;
    }

    int temp[tsz];

    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            temp[y] = arr[i];
            y++;
        }
    }

    for (int i = 0; i < tsz - 1; i++)
    {
        for (int j = 0; j < tsz - i - 1; j++)
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
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = temp[idx];
            idx++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sortoddidx(int N, int *arr)
{
    int y = 0, tsz = 0;

    if (N % 2 == 0)
    {
        tsz = N / 2;
    }
    else
    {
        tsz = (N + 1) / 2;
    }

    int temp[tsz];

    for (int i = 0; i < N; i++)
    {
        if (i % 2 != 0)
        {
            temp[y] = arr[i];
            y++;
        }
    }

    for (int i = 0; i < tsz - 1; i++)
    {
        for (int j = 0; j < tsz - i - 1; j++)
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
    for (int i = 0; i < N; i++)
    {
        if (i % 2 != 0)
        {
            arr[i] = temp[idx];
            idx++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
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

    int choice;
    printf("\nChoose an option:\n");
    printf("1. Sort odd indices\n");
    printf("2. Sort even indices\n");
    printf("3. Insert element at given index\n");
    printf("4. Traverse the array\n");
    printf("5. Reverse the array\n");
    printf("6. Sort the array\n");
    printf("7. Even element sorting\n");
    printf("8. Odd element sorting\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Sorting odd indices\n");
        sortoddidx(N, arr);
        break;

    case 2:
        printf("Sorting even indices\n");
        sortevenidx(N, arr);
        break;

    case 3:
        printf("Inserting element at given index\n");
        insert(N, arr);
        break;

    case 4:
        printf("Traversing the array\n");
        traverse(arr, N);
        break;

    case 5:
        printf("Reversing the array\n");
        reverse(N, arr);
        break;

    case 6:
        printf("Sorting the array\n");
        sort(arr, N);
        break;

    case 7:
        printf("Even element sorting\n");
        evenelsort(N, arr);
        break;

    case 8:
        printf("Odd element sorting\n");
        oddelsort(N, arr);
        break;

    default:
        printf("Invalid choice\n");
    }

    return 0;
}
