#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stack
{
    int val;
    struct stack *next;
} Stack;

bool numbercheck(char c)
{
    return (c >= '0' && c <= '9');
}

Stack *push(Stack *top, int element)
{
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    new_node->val = element;
    new_node->next = top;
    return new_node;
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

int calculate_expression(const char *str)
{
    Stack *top = NULL;

    for (int i = 0; i < strlen(str); i++)
    {
        char c = str[i];

        if (numbercheck(c))
        {
            top = push(top, c - '0'); // Convert char to int
        }
        else if (c == ' ')
        {
            continue; // Ignore spaces
        }
        else
        {
            if (top == NULL || top->next == NULL)
            {
                printf("Error: Not enough operands\n");
                exit(EXIT_FAILURE);
            }

            int a = top->val;
            top = pop(top);
            int b = top->val;
            top = pop(top);

            switch (c)
            {
            case '+':
                top = push(top, b + a);
                break;
            case '-':
                top = push(top, b - a);
                break;
            case '*':
                top = push(top, b * a);
                break;
            case '/':
                if (a != 0)
                {
                    top = push(top, b / a);
                }
                else
                {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                printf("Invalid character encountered: %c\n", c);
                exit(EXIT_FAILURE);
            }
        }
    }

    int result = top->val;
    free(top);
    return result;
}

int main()
{
    char str[100];

    printf("Enter the postfix expression: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    if (strlen(str) == 0)
    {
        printf("Input is empty. Please enter a valid expression.\n");
        return 1;
    }

    int result = calculate_expression(str);
    printf("The result is %d\n", result);

    return 0;
}