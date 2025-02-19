#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *creation_node(int el)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->data = el;
        new_node->next = NULL;
    }
    else
    {
        printf("Memory allocation failed\n");
    }
    return new_node;
}

void combine_nodes(Node **head, int el)
{
    Node *new_node = creation_node(el);
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

combining_two_linked_list(Node *head1, Node *head2)
{
    Node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
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

Node *reverse_list(Node **head)
{
    Node *curr_node = *head;
    Node *prev_node = NULL;
    Node *next_node = NULL;

    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    return prev_node;
}

void Number_of_elements(int N)
{
    Node *head = NULL;
    int new_el;
    int position;
    int ran_el;
    int prev_el;

    for (int i = 0; i < N; i++)
    {
        printf("enter element no.%d ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head, el);
        printf("created %d node\n", i + 1);
    }
    print_list(head);

    printf("enter the element you want insert: ");
    scanf("%d", &new_el);

    printf("enter the element after which you want to insert the element: ");
    scanf("%d", &prev_el);
    New_ins_el(new_el, prev_el, head);
    print_list(head);

    printf("enter the at position which you want to insert the element: ");
    scanf("%d", &position);

    printf("enter the element you want to insert: ");
    scanf("%d", &ran_el);

    New_atpostion(ran_el, position, head);

    printf("after insertion\n");
    print_list(head);

    int del_pos;
    printf("enter the position of the element you want to delete: ");
    scanf("%d", &del_pos);
    delete_node(del_pos, head);
    printf("after deletion\n");
    print_list(head);


    Node *head1 = NULL;
    Node *head2 = NULL;

    int N1;
    printf("enter the number of nodes you want to create: ");
    scanf("%d", &N1);

    for (int i = 0; i < N1; i++)
    {
        printf("enter element no.%d ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head1, el);
        printf("created %d node\n", i + 1);
    }

    int N2;
    printf("enter the number of nodes you want to create: ");
    scanf("%d", &N2);

    for (int i = 0; i < N2; i++)
    {
        printf("enter element no.%d ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head2, el);
        printf("created %d node\n", i + 1);
    }

    combining_two_linked_list(head1, head2);
    print_list(head1);

}

int main()
{
    int N;
    printf("enter the number of nodes you want to create: ");
    scanf("%d", &N);
    Number_of_elements(N);
    return 0;
}
