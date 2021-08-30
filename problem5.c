/*
 * Program to remove duplicates from sorted linked list
 * Compilation : gcc problem5.c
 * Execution : ./a.out
 * Ankush Chhabra 1910990144 29-08-2021
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


struct ListNode* deleteDuplicates(struct ListNode* head){
        struct ListNode *prev=malloc(sizeof(struct ListNode));
        prev=head;
        if(prev==NULL)
        {
            return head;
        }
       struct ListNode *prev2=malloc(sizeof(struct ListNode));
        struct ListNode *temp=malloc(sizeof(struct ListNode));
        temp=NULL;
        if(head->next!=NULL)
            prev2=head->next;
        else
        {
            return head;
        }
        while(prev2!=NULL)
        {
            if(prev2->val==prev->val)
            {   
                //if prev2 and prev are equal then skip that element and make a jump of 1 of prev2
                while(prev2!=NULL && prev2->val==prev->val)
                {
                    prev2=prev2->next;
                }
                if(prev2==NULL)
                {
                    if(temp!=NULL)
                        temp->next=NULL;
                    else
                        head=NULL;
                    continue;
                }
            }
            else
            {
                if(temp==NULL)
                {
                    temp=prev;
                    head=prev;
                }
                else
                {
                    temp->next=prev;
                    temp=prev;
                }
                //prev will be equal to prev2 and prev2 is shifted by 1
                prev=prev2;
                prev2=prev2->next;
                continue;
            }
            if(prev2==NULL)
            {
                prev->next=NULL;
                continue;
            }
             //prev will be equal to prev2 and prev2 is shifted by 1
            prev=prev2;
            prev2=prev2->next;
            //if prev2 is NULL then it means we reached the last node
            if(prev2==NULL)
            {
                //if temp!=NULL then it means temp will be the tail
                if(temp!=NULL){
                temp->next=prev;
                temp=prev;
                temp->next=NULL;
                }
                else
                {   
                    //else temp will be the head.It is possible when all elements are equal 
                    head=prev;
                }
            }
        }
        return head;    
}
