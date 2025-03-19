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

void combine_sorted(Node **head1, Node **tail1, Node **head2, Node **tail2)
{
    Node *head3 = NULL;
    Node *tail3 = NULL;

    (*tail1)->next = NULL;
    (*tail2)->next = NULL;

    Node *temp1 = *head1;
    Node *temp2 = *head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            combine_nodes(&head3, &tail3, temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            combine_nodes(&head3, &tail3, temp2->data);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        combine_nodes(&head3, &tail3, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        combine_nodes(&head3, &tail3, temp2->data);
        temp2 = temp2->next;
    }

    print_list(head3, tail3);
}

int main()
{
    int N;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &N);

    Node *head1 = NULL;
    Node *tail1 = NULL;
    for (int i = 0; i < N; i++)
    {
        int el;
        scanf("%d", &el);
        combine_nodes(&head1, &tail1, el);
    }

    print_list(head1, tail1);

    Node *head2 = NULL;
    Node *tail2 = NULL;

    int M;
    printf("Enter the number of nodes in 2nd circular linked list: ");
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int el;
        scanf("%d", &el);
        combine_nodes(&head2, &tail2, el);
    }

    print_list(head2, tail2);

    combine_sorted(&head1, &tail1, &head2, &tail2);

    printf("\n");
    return 0;
}
