#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode *newNode(int val)
{
    struct ListNode *ptr = NULL;
    ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!ptr)
    {
        printf("malloc failed\n");
        exit(0);
    }
    
    memset(ptr, 0, sizeof(struct ListNode));
    ptr->val = val;
    
    return ptr;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *resultTail = NULL;
    struct ListNode *node = NULL;
    struct ListNode result = {0, NULL};
    int carry = 0;
    int sum = 0;
    
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;
    
    resultTail = &result;
    
    while (l2 || l1)
    {
        sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        
        node = newNode((sum + carry) % 10);
        carry = (sum + carry) / 10;
        resultTail->next = node;
        resultTail = resultTail->next;
    }
    
    if (carry)
    {
        node = newNode(1);
        resultTail->next = node;
    }
    
    return result.next;
}


static void printList(ListNode *list)
{
    ListNode *ptr = NULL;
    
    if (!list)
        return;
    
    ptr = list;
    
    while (ptr)
    {
        printf("%d ---> ", ptr->val);
        ptr = ptr->next;
    }
    
    printf("\n");
    return;
    
}

int main(int argc, char const *argv[])
{
    /* code */
    ListNode l1 = {5, NULL};
    ListNode l2 = {5, NULL};
    
    ListNode *result = NULL;
    
    result = addTwoNumbers(&l1, &l2);
    
    printList(result);
    return 0;
}




