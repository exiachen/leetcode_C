#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode smallHead = {0, 0};
    struct ListNode biggerHead = {0, 0};
    struct ListNode *ptr = NULL;
    struct ListNode *smallPtr = &smallHead;
    struct ListNode *biggerPtr = &biggerHead;


    if (!head)
        return NULL;

    ptr = head;

    while (ptr)
    {
        if (ptr->val < x)
        {
            smallPtr->next = ptr;
            smallPtr = ptr;
        }
        else
        {
            biggerPtr->next = ptr;
            biggerPtr = ptr;
        }

        ptr = ptr->next;
    }

    smallPtr->next = biggerHead.next;
    biggerPtr->next = NULL;

    return smallHead.next;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}