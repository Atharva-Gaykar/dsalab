#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *insert(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node != NULL)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return new_node;
}

void Bubble_Sort_list(Node *head, int N)
{
    if (head == NULL)
        return;

    for (int i = 0; i < N - 1; i++)
    {
        Node *curr_node = head;
        Node *next_node = head->next;

        for (int j = 0; j < N - 1 - i; j++)
        {
            if (curr_node->data > next_node->data)
            {
                int temp = curr_node->data;
                curr_node->data = next_node->data;
                next_node->data = temp;
            }

            curr_node = next_node;
            next_node = next_node->next;
        }
    }
}

void combine_nodes(Node **head, int el)
{
    Node *new_node = insert(el);

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(Node *head)
{
    Node *temp = head;
    int count_nodes = 0;

    while (temp != NULL)
    {
        printf("the element %d\n", temp->data);
        count_nodes++;
        temp = temp->next;
    }

    printf("the number of nodes %d\n", count_nodes);
}

int main()
{
    Node *head = NULL;

    int N;
    printf("enter the no of elements in the list\n");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int el;
        printf("enter the element\n");
        scanf("%d", &el);
        combine_nodes(&head, el);
    }

    print_list(head);

    Bubble_Sort_list(head, N);
    print_list(head);

    return 0;
}
