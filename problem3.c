/*
 * Program to Implement Dequeue using Linked List
 * Compilation : gcc problem3.c
 * Execution : ./a.out
 * Ankush Chhabra 1910990144 29-08-2021
 * Assignment_6 -> Linked List
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//Initializing next , prev and data value of a doubly linked list
struct ListNode
{
    struct ListNode *next;
    struct ListNode *prev;
    int data;
};


// Creating head , tail of Doubly Linked List and current size variable.
struct ListNode *head;
struct ListNode *tail;
int sz;

void initialize_deque()
{
    head = NULL;
    tail = NULL;
    sz = 0;
}


// Function to enqueue an element at front of deque using Doubly Linked List Node.
void enqueue_front(int val)
{
    // creating a new Doubly linked list node and assigning val to its data and NULL to its next and prev.
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    else if(tail == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL; 
    }
    // attach head of present Doubly Linked list to newNode and point head to newNode to add a node at front.
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        newNode->prev = NULL;
    }
    printf("Enqueuing %d at front of deque \n" , val);
    sz++;
}
// Function to enqueue an element at rear of deque using Doubly Linked List Node.
void enqueue_rear(int val)
{
    // creating a new Doubly linked list node and assigning val to its data and NULL to its next and prev.
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    // if head is NULL ,means size is 0 so just point head and tail to newNode and head's next and prev to NULL.
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    else if( tail == NULL )
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    // attach newNode to tail of current Doubly Linked List and move tail one place ahead.
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
    }
    printf("Enqueuing %d at rear of deque \n" , val);
    sz++;
}
// Function to dequeue an element from front of deque , which is also the element at head of Doubly Linked List.
int dequeue_front()
{
    if(sz == 0)
    {
        printf("Deque is empty\n");
        return -1;
    }
    
    //store the first element of the Doubly Linked List and return it
    struct ListNode *temp = head;
    int data = head->data;
    head = head->next;
    if(head != NULL)
    {
        head->prev = NULL;//break the link with previous node
    }
    sz--;
    free(temp);
    
    return data;
}


// Function to dequeue an element from rear of deque , which is also the element at tail of Doubly Linked List.
int dequeue_rear()
{
    if(sz == 0)
    {
        printf("Deque is empty\n");
        return -1;
    }
    
     //store the last element of the Doubly Linked List and return it
    struct ListNode *temp = tail;
    int data = tail->data;
    tail = tail->prev;
    if(tail != NULL)
    {
        tail->next = NULL;//break the link with last element
    }
    
    // decrease the size and free the rear node.
    sz--;
    free(temp);
    
    // return data of rear node which was dequeued out.
    return data;
}


// Function to return front node data of deque , without removing it.
int peek_front()
{
    if(sz == 0)
    {
        printf("Deque is empty\n");
        return -1;
    }
    
    int temp = head->data;
    return temp;
}


// Function to return rear node data of deque , without removing it.
int peek_rear()
{
    if(sz == 0)
    {
        printf("Deque is empty \n");
        return -1;
    }
    
    int temp = tail->data;
    return temp;
}


// Function to check if a particular element is present in deque or not.
bool is_present(int key)
{
    if(sz == 0)
    {
        return 0;
    }
    
    // Node to traverse the Doubly Linked List.
    struct ListNode *temp = head;
    
    while(temp != NULL)
    {
        // if key found , return 1.
        if(temp->data == key)
        {
            return 1;
        }
        
        temp = temp->next;
    }
    
    // if key not found , return 0.
    return 0;
}


// Function to check is deque is empty or not.
bool is_empty()
{
    if(sz == 0)
    {
        return 1;
    }
    
    return 0;
}

int get_size()
{
    return sz;
}

// Main function to show working of this deque.
int main() 
{
    initialize_deque();
    enqueue_front(1);
    enqueue_front(2);
    enqueue_rear(3);
	
    printf("Current size = %d\n" , get_size());
	
    int dequeued_rear = dequeue_rear();
    if(dequeued_rear != -1)
    {
        printf("Dequeued element from rear = %d\n" , dequeued_rear);
    }
	
    printf("Is %d present in deque or not : %d \n" , dequeued_rear , is_present(dequeued_rear));
	
    printf("Peek element from rear = %d\n" , peek_rear());
	
    int dequeued_front = dequeue_front();
    if(dequeued_front != -1)
    {
        printf("Dequeued element from front = %d\n" , dequeued_front);
    }
	
    printf("Current size = %d\n" , get_size());
    printf("Is deque empty or not : %d\n" , is_empty());
	
    printf("Peek element from front = %d\n" , peek_front());
	
    printf("Is %d present in deque or not : %d \n" , 30 , is_present(30));
	
    printf("Is deque empty ? : %d\n" , is_empty());

    return 0;

}
