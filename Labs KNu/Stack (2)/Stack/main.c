#include <time.h>

#include "stack.h"

int main()
{
    srand(time(NULL));

    stack* head = NULL;             // Pointer to the head of empty dynamic structure
    push(&head, rand()%10);         // Pushing element on the top of stack
    show(head);                     // Printing the content of the stack
    system("pause");

    system("@cls||clear");
    push(&head, rand()%10);
    push(&head, rand()%10);
    show(head);
    system("pause");

    system("@cls||clear");
    push(&head, rand()%10);
    push(&head, rand()%10);
    push(&head, rand()%10);
    show(head);
    system("pause");

    system("@cls||clear");
    int v = pop(&head);             // Taking element from the top of the stack
    show(head);
    system("pause");

    system("@cls||clear");
    clear(&head);                   // Clearning all elements from the stack before the program finishes
    show(head);
    system("pause");

    return 0;
}
