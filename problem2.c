/*
 * Program to Implement Queue using Linked List
 * Compilation : gcc problem2.c
 * Execution : ./a.out
 * Ankush Chhabra 1910990144 29-08-2021
 * Assignment_6 -> Linked List
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Creating a structure node (Linked List Node) to contain next node address and data of its node.
struct ListNode
{
    struct ListNode *next;
    int data;
};

struct ListNode *head;
struct ListNode *tail;
int sz;//size of the queue


// Function to initialize queue by making head = NULL , tail = NULL and size = 0.
void initialize_queue()
{
    head = NULL;
    tail = NULL;
    sz = 0;
}


// Function to enqueue an element into queue using Linked List Node.
void enqueue(int val)
{
    // creating a new linked list node and assigning val to its data and NULL to its next.
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->data = val;
    newNode->next = NULL;
    //if head is NULL then it means we are adding the first element in the queue so initialize head to newNode
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
    }
    
    // else add newNode at the end means linking to the tail 
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    
    printf("Enqueuing %d  \n" , val);
    
    // increase size.
    sz++;
}
//Function to dequeue the element
int dequeue()
{
    //If size is zero then it means queue is empty
    if(sz == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    //Store the front element of the Linked list which will be the dequeued element of the queue
    struct ListNode *store = head;
    int data = head->data;
    head = head->next;
    
    // decrease the size and free the front node.
    sz--;
    free(store);
    
    // return data of front node which was popped out.
    return data;
}

// Function to check is queue is empty or not.
bool is_empty()
{
    if(sz == 0)
    {
        return 1;
    }
    
    return 0;
}


// Function to return front element of queue , without removing it.
int peek()
{
    if(sz == 0)
    {
        printf(" No element at front \n");
        return -1;
    }
    
    int temp = head->data;
    return temp;
}


// Function to return current size of queue.
int get_size()
{
    return sz;
}


// Main function to show working of this queue.
int main() 
{
    initialize_queue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
	
    printf("Current size = %d\n" , get_size());
	
    int dequeued = dequeue();
    if(dequeued != -1 )
    {
        printf("Dequeued element = %d\n" , dequeued);
    }
	
    printf("Peek element = %d\n" , peek());
	
    dequeued = dequeue();
    if(dequeued != -1 )
    {
        printf("Dequeued element = %d\n" , dequeued);
    }
	
    printf("Current size = %d\n" , get_size());
	
    printf("Peek element = %d\n" , peek());
	
    printf("Is queue empty : %d\n" , is_empty());

    return 0;

}
