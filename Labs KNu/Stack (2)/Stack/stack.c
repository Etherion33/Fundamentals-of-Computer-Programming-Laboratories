

#include "stack.h"

/***
    Creating element to add to dynamic structure.
***/
stack* element(int v)
{
    stack* element = (stack*) malloc(sizeof(stack));    // Allocating memory for new element
    element->value = v;                                 // Assigning values
    element->next = NULL;                               // Setting the linking pointer to NULL -> if forgotten other function will not work correctly
    return element;
}

void push(stack** head, int v)
{
    stack* next = element(v);                           // Create new element

    if(*head == NULL)                                   // If dynamic structure is empty
    {
        *head = next;                                   // Head becomes the first element
    }
    else                                                // When there are elements in the structure
    {
        next->next = *head;                             // Whole dynamic structure is linked to the end of new element
        *head = next;                                   // New element becomes the head
    }
}

int pop(stack** head)
{
    if(*head!=NULL)                                     // If the stack exists
    {
        stack* nextElement = (*head)->next;             // Save pointer to the second element of dynamic structure
        int v = (*head)->value;                         // Save value from first element on the stack
        free(*head);                                    // Free memory allocated for first element
        *head = nextElement;                            // Second element becomes the head
        return v;                                       // Returning value
    }
    else
    {
        return -1;                                      // Proper value returned when the stack is empty
    }
}


void clear(stack** head)
{
    while(*head != NULL)                                // As long as there are elements in the stack
    {
        stack* next = (*head)->next;                    // Save pointer to the second element
        free(*head);                                    // Free memory allocated for the first element
        *head = next;                                   // Second element becomes the head
    }
}

void show(stack* head)
{
    stack* dummy = head;                                // Dummy element to assure that we will not loose the pointer to the head
    while(dummy!=NULL)                                  // As long there are elements in the stack
    {
        printf("/---------\\ \n");
        printf("|   %d     | \n", dummy->value);        // Print a value
        printf("\\---------/ \n");
        dummy = dummy->next;                            // Move to next element
    }
}
