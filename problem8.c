/*
 * Program to reverse a part of linked list
 * Compilation : gcc problem8.c
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
        struct ListNode *head=malloc(sizeof(struct ListNode));
        head=NULL;
        struct ListNode *tail=malloc(sizeof(struct ListNode));
        tail=NULL;
        while(l1!=NULL && l2!=NULL)
        {
            //if data of node at position l1 is greater than data of node at position l2 then shift l2 by               1 else shift l1 by 1
            if(l1->val>l2->val)
            {
                if(head==NULL)
                {
                    head=l2;
                    tail=l2;
                }
                else
                {
                    tail->next=l2;
                    tail=l2;
                }
                l2=l2->next;
            }
            else
            {
                if(head==NULL)
                {
                    head=l1;
                    tail=l1;
                }
                else
                {
                    tail->next=l1;
                    tail=l1;
                }
                l1=l1->next;
            }
        }
        //add the remaining values of l1 
        while(l1!=NULL)
        {
            if(tail==NULL)
            {
                head=l1;
                tail=l1;
            }
            else{
            tail->next=l1;
            tail=l1;
            }
            l1=l1->next;
        }
        //add the remaining values of l2
        while(l2!=NULL)
        {
            if(tail==NULL){
                tail=l2;
                head=l2;
            }
            else{
            tail->next=l2;
            tail=l2;
            }
            l2=l2->next;
        }
        if(tail!=NULL)
        tail->next=NULL;
        return head;
}
