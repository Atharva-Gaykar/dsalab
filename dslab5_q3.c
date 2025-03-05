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

void merge(Node *head1, Node *head2) {
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *head3 = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data <= temp2->data) {
            combine_nodes(&head3, temp1->data);
            temp1 = temp1->next;
        } else {
            combine_nodes(&head3, temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        combine_nodes(&head3, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        combine_nodes(&head3, temp2->data);
        temp2 = temp2->next;
    }

    print_list(head3);
}

void Number_of_elements(int N1, int N2) {
    Node *head1 = NULL;
    Node *head2 = NULL;
    int new_el;
    for (int i = 0; i < N1; i++) {
        printf("enter element no.%d ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head1, el);
        printf("created %d node\n", i + 1);
    }
    print_list(head1);

    for (int i = 0; i < N2; i++) {
        printf("enter element no.%d ", i + 1);
        int el;
        scanf("%d", &el);
        combine_nodes(&head2, el);
        printf("created %d node\n", i + 1);
    }
    print_list(head2);

    merge(head1, head2);
}

int main() {
    int N1, N2;
    printf("enter the number of nodes you want to create L1 ");
    scanf("%d", &N1);
    printf("enter the number of nodes you want to create L2");
    scanf("%d", &N2);

    Number_of_elements(N1, N2);
    return 0;
}
