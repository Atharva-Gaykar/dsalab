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
        new_node->prev = temp;
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

void print_list_reverse(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

Node *return_tail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void insert_el(int position, int new_el, Node **head, int N)
{
    if (position < 1 || position > N + 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1)
    {
        Node *new_node = creation_node(new_el);
        new_node->next = *head;
        if (*head != NULL)
            (*head)->prev = new_node;
        *head = new_node;
        print_list(*head);
        return;
    }
    Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    Node *new_node = creation_node(new_el);
    new_node->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
    print_list(*head);
}

void delete_el(int position, Node **head, int N){


    if (position < 1 || position > N + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        Node* temp=*head;
        *head=temp->next;
        temp->next->prev=NULL;
        free(temp);
        return;
    }
    
    


    Node* temp=*head;

    for (int i = 1; i < position-1 && temp != NULL; i++)
    {
        temp=temp->next;
    }

    Node* prev_node=temp;
    temp=temp->next;
    temp->next->prev=prev_node;
    prev_node->next=temp->next;
    free(temp);
    
}

void Number_of_elements(int N)
{
    Node *head = NULL;
    for (int i = 0; i < N; i++)
    {
        printf("Enter element no.%d: ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head, el);
        printf("Created node %d\n", i + 1);
    }
    print_list(head);
    printf("List in reverse order: ");
    print_list_reverse(head);

    int position, new_el;
    printf("Enter the position to insert a new element: ");
    scanf("%d", &position);
    printf("Enter the value of the new element: ");
    scanf("%d", &new_el);

    insert_el(position, new_el, &head, N);


    int del_position;
    printf("Enter the position to delete an element: ");
    scanf("%d", &del_position);

    delete_el(del_position, &head, N);
}

int main()
{
    int N;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &N);
    Number_of_elements(N);

    return 0;
}
