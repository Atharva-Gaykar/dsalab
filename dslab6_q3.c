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
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void combine_nodes(Node **head, Node **tail, int el)
{
    Node *new_node = insert(el);

    if (*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
        (*tail)->next = *head;
    }
    else
    {
        new_node->next = (*tail)->next;
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

void print_list(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}


int main()
{
    int N;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &N);
    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < N; i++)
    {
        int el;
        scanf("%d", &el);
        combine_nodes(&head, &tail, el);
    }

    print_list(head, tail);
    printf("\n");

    reverse_circular_list(&head, &tail);

    return 0;
}
