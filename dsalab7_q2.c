#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return;
    }
    printf("%d popped from stack\n", s->arr[s->top--]);
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", s->arr[s->top]);
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initialize(&s);
    
    int N;
    printf("Enter the number of elements to push into the stack: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int el;
        scanf("%d", &el);
        push(&s, el);
    }

    printStack(&s);
    pop(&s);
    peek(&s);
    printStack(&s);

    return 0;
}