/*
 * Check if singly linked list is palindrome or not
 * Compilation : gcc problem4.c
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
//Function to reverse the linked list
struct ListNode *reverse(struct ListNode *head)
{
    if(head->next==NULL)
	{
		return head;
	}
	struct ListNode *temp=malloc(sizeof(struct ListNode));
    temp=reverse(head->next);
	struct ListNode *tail=malloc(sizeof(struct ListNode));
    tail=head->next;
	tail->next=head;
	head->next=NULL;
	return temp;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode *temp=malloc(sizeof(struct ListNode));
        temp=head;
        int sz=0;
        if(head->next==NULL)
        {
            return true;
        }
        //Find the size of the linked list
        while(temp!=NULL)
        {
            temp=temp->next;
            sz++;
        }
        temp=head;
        struct ListNode *temp1=malloc(sizeof(struct ListNode));
        temp1=head;
        int cnt=1;
        //traverse till the half of the linked list
        while(temp!=NULL)
        {
            if(cnt==sz/2)
            {
                temp1=temp->next;
                temp->next=NULL;
                break;
            }
            temp=temp->next;
            cnt++;
        }
        if(sz%2)
            temp1=temp1->next;
        //reverse the first half of the linked list
        temp=reverse(head);
        //comparing the first and second half of linked list. If they are equal then the linked list is             palindrome
        while(temp!=NULL && temp1!=NULL)
        {
            if(temp->val != temp1->val)
                return false;
            temp=temp->next;
            temp1=temp1->next;
        }
        return true;
}
