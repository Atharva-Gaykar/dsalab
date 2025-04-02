#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct stack
{
    char val;
    struct stack *next;
} Stack;

int numbercheck(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}

int priority_check(char stack_element, char str_element)
{
    char A[] = {'^', '*', '/', '+', '-'};
    int B[] = {5, 4, 4, 3, 3};
    int prio_stack = 0, prio_str = 0;

    for (int i = 0; i < 5; i++)
    {
        if (stack_element == A[i])
        {
            prio_stack = B[i];
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (str_element == A[i])
        {
            prio_str = B[i];
            break;
        }
    }

    if (prio_stack >= prio_str)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Stack *push(Stack *top, char element)
{
    Stack *new_node = new Stack;
    new_node->val = element;
    new_node->next = top;
    top = new_node;
    return top;
}

Stack *pop(Stack *top)
{
    if (top == NULL)
    {
        return NULL;
    }
    Stack *temp = top;
    top = top->next;
    delete temp;
    return top;
}

void converter_postfix(string q_str)
{
    Stack *top = NULL;
    string ans;

    for (int i = 0; i < q_str.length(); i++)
    {
        if (q_str[i] == ' ')
        {
            continue;
        }
        else if (q_str[i] == '(')
        {
            top = push(top, q_str[i]);
        }
        else if (numbercheck(q_str[i]))
        {
            // Handle multi-digit numbers
            while (i < q_str.length() && numbercheck(q_str[i]))
            {
                ans = ans + q_str[i];
                i++;
            }
            i--; // Adjust for the last increment
            ans += ' '; // Add space to separate numbers
        }
        else if (q_str[i] == ')')
        {
            while (top != NULL && top->val != '(')
            {
                ans = ans + top->val;
                ans += ' '; // Add space to separate operators
                top = pop(top);
            }

            if (top == NULL)
            {
                cout << "Invalid expression: Mismatched parentheses." << endl;
                return;
            }

            top = pop(top); // Pop the '('
        }
        else
        {
            while (top != NULL && priority_check(top->val, q_str[i]) == 1)
            {
                ans = ans + top->val;
                ans += ' '; // Add space to separate operators
                top = pop(top);
            }
            top = push(top, q_str[i]);
        }
    }

    while (top != NULL)
    {
        if (top->val == '(')
        {
            cout << "Invalid expression: Mismatched parentheses." << endl;
            return;
        }
        ans = ans + top->val;
        ans += ' '; // Add space to separate operators
        top = pop(top);
    }

    cout << "The postfix expression is: " << ans << endl;
}

int main()
{
    string q_str;

    cout << "Enter the infix expression: ";
    getline(cin, q_str);

    if (q_str.empty())
    {
        cout << "Input is empty. Please enter a valid expression." << endl;
        return 1;
    }

    converter_postfix(q_str);

    return 0;
}