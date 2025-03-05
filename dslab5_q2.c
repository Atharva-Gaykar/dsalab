#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* creation_node(int el) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = el;
        new_node->next = NULL;
    } else {
        printf("Memory allocation failed\n");
    }
    return new_node;
}

void combine_nodes(Node **head, int el) {
    Node *new_node = creation_node(el);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(Node *head) {
    Node *temp = head;
    int count_nodes = 0;
    while (temp != NULL) {
        printf("the element %d\n", temp->data);
        count_nodes++;
        temp = temp->next;
    }
    printf("the number of nodes %d\n", count_nodes);
}

void even_odd(Node *head) {
    Node *head_even = NULL;
    Node *head_odd = NULL;
    Node *temp = head;
    int count_nodes = 1;
    while (temp != NULL) {
        if (count_nodes % 2 == 0) {
            combine_nodes(&head_even, temp->data);
        } else {
            combine_nodes(&head_odd, temp->data);
        }
        count_nodes++;
        temp = temp->next;
    }
    printf("even position LL\n");
    print_list(head_even);
    printf("\nodd position LL\n");
    print_list(head_odd);
}

void Number_of_elements(int N) {
    Node *head = NULL;
    int new_el;
    for (int i = 0; i < N; i++) {
        printf("enter element no.%d ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head, el);
        printf("created %d node\n", i + 1);
    }
    print_list(head);
    even_odd(head);
}

int main() {
    int N;
    printf("enter the number of nodes you want to create ");
    scanf("%d", &N);
    Number_of_elements(N);
    return 0;
}
