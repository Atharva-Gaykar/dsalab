#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *creation_node(int el)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->data = el;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        printf("Memory allocation failed\n");
    }
    return new_node;
}

void combine_nodes(Node **head, int el, Node **tail)
{
    Node *new_node = creation_node(el);
    if (*head == NULL)
    {
        *head = new_node;
        *tail = new_node;
        (*tail)->next = *head;
        (*head)->prev = *tail;
    }
    else
    {
        new_node->next = (*tail)->next;
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
        (*head)->prev = *tail;
    }
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void check_palidrome(Node *head, Node *tail)
{

    Node *temp1 = head;
    Node *temp2 = tail;
    int flag = 0;

    while (temp1 != tail && temp2 != head)
    {

        if (temp1->data != temp2->data)
        {

            flag = 1;

            printf("Not a palidrome\n");
            return;
        }

        temp1 = temp1->next;
        temp2 = temp2->prev;
    }

    if (flag == 0)
    {

        if (tail->data == head->data)
        {
            printf("Palidrome\n");
        }
        else
        {
            printf("Not a palidrome\n");
        }
    }
}

void Number_of_elements(int N)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < N; i++)
    {
        printf("Enter element no.%d: ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head, el, &tail);
        printf("Created node %d\n", i + 1);
    }

    check_palidrome(head, tail);
}

int main()
{
    int N;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &N);
    Number_of_elements(N);

    return 0;
}
