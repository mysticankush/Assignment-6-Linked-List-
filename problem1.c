/*
 * Program to Implement Stack using Linked List
 * Compilation : gcc problem1.c
 * Execution : ./a.out
 * Ankush Chhabra 1910990144 29-08-2021
 * Assignment_6 -> Linked List
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode
{
    struct ListNode *next;
    int data;
};

struct ListNode *head;
int size;


// Function to initialize stack by making head = NULL and size = 0.
void initialize_stack()
{
    head = NULL;
    size = 0;
}


// Function to push an element into stack using Linked List Node.
void push(int val)
{
    // creating a new linked list node and assigning val to its data and NULL to its next.
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->data = val;
    newNode->next = NULL;   
    //If head is not pointing to any node then it will be newNode initially
    if(head == NULL)
    {
        head = newNode;
        head->next = NULL;
    }
    // else attach newNode at front of linked list
    else
    {
        newNode->next = head;
        head = newNode;
    }
    
    printf("Added %d at top of stack \n" , val);
    
    size++;
}

// Function to pop an element from top of stack , which is also the element at head of Linked List.
int pop()
{
    if(size == 0)
    {
        printf("Nothing to remove , stack is empty\n");
        return -1;
    }
    //Extract first element of linked list which is the front element and delete that node
    struct ListNode *temp = head;
    int data = head->data;
    head = head->next;
    
    // decrease the size and free the top node.
    size--;
    free(temp);
    
    // return data of top node which was popped out.
    return data;
}

// Function to check is stack is empty or not.
bool is_empty()
{
    if(size == 0)
    {
        return 1;
    }
    
    return 0;
}


// Function to return top element of stack , without removing it.
int peek()
{
    if(size == 0)
    {
        printf("Stack is empty , no element at top \n");
        return -1;
    }
    
    int temp = head->data;
    return temp;
}


// Function to return current size of stack.
int get_size()
{
    return size;
}

// Main function to show working of this stack.
int main() 
{
    initialize_stack();
    push(1);
    push(2);
    push(3);
	
    printf("Current size = %d\n" , get_size());
	
    int popped = pop();
    if(popped != -1)
    {
        printf("Popped element = %d\n" , popped);
    }
	
    printf("Peek element = %d\n" , peek());
	
    popped = pop();
    if(popped != -1)
    {
        printf("Popped element = %d\n" , popped);
    }
	
    printf("Peek element = %d\n" , peek());
	
    printf("Is stack empty ? : %d\n" , is_empty());
	
    return 0;
}
