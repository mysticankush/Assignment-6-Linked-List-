/*
 * Program to rotate the linked list by k positions
 * Compilation : gcc problem9.c
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


struct ListNode* rotateRight(struct ListNode* head, int k){
     int sz=0;
        struct ListNode *temp=malloc(sizeof(struct ListNode));
        temp=head;
        if(temp==NULL)
            return head;
        //find size of linked list
        while(temp!=NULL)
        {
            sz++;
            temp=temp->next;
        }
        //rotate the linked list by k%sz places
        k=k%sz;
        //if k==0 then it means linked list is not rotated it is same
        if(k==0)
            return head;
        temp=head;
        int cnt=0;
        int req=sz-k+1;
        req--;
        struct ListNode *store=malloc(sizeof(struct ListNode));
        //cut the linked list at position req into two halves i.e. left and right
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==req)
            {
                //store the first element of second half
                store=temp->next;
                temp->next=NULL;
                break;
            }            
            temp=temp->next;
        }
        temp=head;
        //make first element of second half as head
        head=store;
        //connect last element of second half with first element of first half 
        while(1)
        {
            if(head->next==NULL)
            {
                head->next=temp;
                break;
            }
            head=head->next;
        }
        //return first element of second half i.e. store which will be the head of rotated linked list
        return store;
}
