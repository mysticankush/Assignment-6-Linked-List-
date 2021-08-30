/*
 * Program to remove nth node from last in a linked list
 * Compilation : gcc problem6.c
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
      struct ListNode *temp=malloc(sizeof(struct ListNode));
      struct ListNode *temp1=malloc(sizeof(struct ListNode));
    temp1=head;
      //jump temp1 to nth node from front
      while(n--)
      {
          temp1=temp1->next;
      }
    //if it is equal to NULL then it means n is equal to the size of linked list.So simple remove first         node
    if(temp1==NULL)
    {
        head=head->next;
        return head;
    }
    //else shift temp till temp1!=NULL and delete the current node of temp
    temp=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
            temp=temp->next;
        }
    temp->next=temp->next->next;
    return head;
}
