#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct stack {
    char val;
    struct stack *next;
} Stack;


Stack *push(Stack *top, char element) {
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    new_node->val = element;
    new_node->next = top;
    return new_node;
}


Stack *pop(Stack *top) {
    if (top == NULL) return NULL;
    Stack *temp = top;
    top = top->next;
    free(temp);
    return top;
}


bool isValid(const char *str) {
    Stack *st = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            st = push(st, str[i]);
        } else {
            if (st == NULL) return false;

            char topChar = st->val;
            if ((topChar == '(' && str[i] == ')') ||
                (topChar == '[' && str[i] == ']') ||
                (topChar == '{' && str[i] == '}')) {
                st = pop(st);
            } else {
                return false;
            }
        }
    }

    return st == NULL;
}

int main() {
    char str[100];

    printf("Enter a string of brackets to validate: ");
    scanf("%s", str);

    if (isValid(str)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}