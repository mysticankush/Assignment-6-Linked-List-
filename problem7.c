/*
 * Program to reverse a part of linked list
 * Compilation : gcc problem7.c
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
//Function to reverse linked list from node temp to temp1
struct ListNode *reverse(struct ListNode *temp,struct ListNode *temp1)
{
    if(temp==temp1)
        return temp1;
    struct ListNode *tail=malloc(sizeof(struct ListNode));
    tail=reverse(temp->next,temp1);
    struct ListNode *head=malloc(sizeof(struct ListNode));
    head=temp->next;
    head->next=temp;
    temp->next=NULL;
    return tail;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
        struct ListNode *temp=malloc(sizeof(struct ListNode));
        temp=head;
        struct ListNode *temp1=malloc(sizeof(struct ListNode));
        temp1=head;
        if(left==right)
            return head;
        int cnt=0;
        //shift temp to left times from head
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==left)
                break;
            temp=temp->next;
        }
       
        cnt=0;
        //shift temp1 to right times from head
        while(temp1!=NULL)
        {
            cnt++;
            if(cnt==right)
                break;
            temp1=temp1->next;
        }
        struct ListNode *store=malloc(sizeof(struct ListNode));
        //store the next element of temp1
        store=temp1->next;
        struct ListNode *temphead=malloc(sizeof(struct ListNode));
        temphead=head;
        struct ListNode *flg=malloc(sizeof(struct ListNode));
        //reverse linked list from temp to temp1
        flg=reverse(temp,temp1);
        cnt=0;
        if(left>1){
        //connect node at position ( left - 1 ) with temp1 or flg
        while(temphead!=NULL)
        {
            cnt++;
          if(cnt==left-1)
          {
              break;
          }
            temphead=temphead->next;
        }
            temphead->next=flg;
        }
        else
        {
           head=flg; 
        }
        //connect node at position temp with store
        temp->next=store;
        return head;
}
