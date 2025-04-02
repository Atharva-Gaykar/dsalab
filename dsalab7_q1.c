#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *newnode(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(node **top, int data)
{
    node *new_node = newnode(data);
    new_node->next = *top;
    *top = new_node;
    printf("%d pushed to stack\n", data);
}

void print_stack(node *top)
{
    if (top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void pop_stack(node **top)
{
    if (*top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    node *temp = *top;
    (*top) = (*top)->next;
    printf("%d popped from stack\n", temp->data);
    free(temp);
}

int main()
{
    node *top = NULL;
    int N;
    printf("enter the number of elements you want to push in stack ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int el;
        scanf("%d", &el);
        push(&top, el);
    }
    print_stack(top);
    return 0;
}