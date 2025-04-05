#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

void breakCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    int isCycle = 0;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            isCycle = 1;
            break;
        }
    }

    if (!isCycle)
    {
        return NULL;
    }

    slow = head;
    ListNode *prev_fast = NULL;

    while (slow != fast)
    {
        slow = slow->next;
        prev_fast = fast;
        fast = fast->next;
    }

    prev_fast->next = NULL;

    
}