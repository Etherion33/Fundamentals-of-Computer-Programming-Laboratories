#ifndef __STACK_H_
#define __STACK_H_

#include <stdlib.h>
#include <stdio.h>

/***
    Element of the stack
***/
typedef struct stack
{
    char* m_title;                      // Value stored in the dynamic structure.
    int m_year;
    int m_rating;
    struct stack* next;             // Element used for linking parts.
}stack;

/***
    Function which pushes value v on the top of the stack.
***/
void push(stack** head, char* title, int year, int rating);
/***
    Function which takes element from the stack top and returns its value.
***/
void pop(stack** head);
/***
    Function clearing all elements in the stack.
***/
void clear(stack** head);
/***
    Function printing all elements in the stack.
***/
void show(stack* head);

#endif // __STACK_H_
