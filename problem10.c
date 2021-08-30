/*
 * Program to find first position where cycle begins in a linked list
 * Compilation : gcc problem10.c
 * Execution : ./a.out
 * Ankush Chhabra 1910990144 30-08-2021
 * Assignment_6 -> Linked List
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
        //initialize fast and slow pointer to head
        struct ListNode *fast=malloc(sizeof(struct ListNode));
        fast = head;
        struct ListNode *slow=malloc(sizeof(struct ListNode));
        slow = head;
        if(fast==NULL)
            return NULL;
        //make a jump of 1 with slow pointer and a jump of 2 with fast pointer
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
                break;           
        }
        // if fast is NULL or fast->next is NULL then it means there is no cycle
        if(fast==NULL || fast->next==NULL)
        {
            return NULL;
        }
        //else initialize slow pointer to head and make a jump if 1 with slow and fast pointers to get the          starting position of cycle
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
}
