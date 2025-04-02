#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    char val;
    struct stack *next;
} Stack;

Stack *push(Stack *top, char element)
{
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    new_node->val = element;
    new_node->next = top;
    top = new_node;
    return top;
}

Stack *pop(Stack *top)
{
    if (top == NULL)
        return NULL;
    Stack *temp = top;
    top = top->next;
    free(temp);
    return top;
}

int check_palindrome(const char *strr)
{
    Stack *top = NULL;
    size_t len = strlen(strr);

    for (size_t i = 0; i < len; i++)
    {
        top = push(top, strr[i]);
    }

    for (size_t i = 0; i < len; i++)
    {
        char ran_char = strr[i];
        if (top == NULL || ran_char != top->val)
        {
            return 0;
        }
        top = pop(top);
    }
    return 1;
}

int main()
{
    char strr[100];

    printf("Enter the string: ");
    fgets(strr, sizeof(strr), stdin);
    strr[strcspn(strr, "\n")] = '\0';

    int result = check_palindrome(strr);

    if (result == 1)
    {
        printf("The given string is a palindrome\n");
    }
    else
    {
        printf("The given string is not a palindrome\n");
    }

    printf("The result is %d\n", result);
    return 0;
}