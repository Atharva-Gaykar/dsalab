#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued: %d\n", val);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty. Cannot dequeue!\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int K[100];
int V[100];

void find_element()
{
    struct Node *temp = front;
    int idx = 0;
    int count = 0;

    while (temp != NULL)
    {
        int el = temp->data;

        if (idx == 0)
        {
            K[idx] = el;
            V[idx] = 1;
            idx++;
            count++;
        }
        else
        {
            int flag = 0;
            for (int i = 0; i < count; i++)
            {
                if (K[i] == el)
                {
                    flag = 1;
                    V[i]++;
                    break;
                }
            }
            if (flag == 0)
            {
                K[idx] = el;
                V[idx] = 1;
                idx++;
                count++;
            }
        }
        temp = temp->next;
    }

    struct Node *trav = front;
    while (trav != NULL)
    {
        int el = trav->data;
        int t = 0;

        for (int i = 0; i < count; i++)
        {
            if (K[i] == el)
            {
                t = V[i];
                break;
            }
        }

        if (t > 1)
        {
            dequeue();
            trav = front; 
        }
        else
        {
            printf("First unique element: %d\n", trav->data);
            break;
        }
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(20);
    enqueue(30);
    enqueue(20);
    enqueue(40);
    display();

    find_element();
    display();

    return 0;
}