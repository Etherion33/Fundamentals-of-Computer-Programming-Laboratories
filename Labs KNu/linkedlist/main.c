#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct linked{
    char* data;
    struct linked *next;

};

struct node {
    char* course;
    struct node *next;
    struct linked *head;
};

void addNode(struct node **head,char* s);
void addlinkednode(struct linked **head,char* prereq);

int main()
{
    struct node *head = NULL,*temp;
    struct linked *head2 = NULL,*temp1;
    char* text[] = {"one", "two", "three",
            "four", "five", "six"};

    char* text2[] = {"john","bravo","gabe"};
    int i, size = sizeof(text)/sizeof(text[0]);
    int size2 = sizeof(text2)/sizeof(text2[0]);


    for(i = 0; i < size; i++)
            addNode(&head, text[i]);

    for(i = 0; i < size2; i++)
            addlinkednode(&head2,text2[i]);
    // For printing...
    temp=head;
    while(temp){
            printf("%s -> ",temp->course);
            temp=temp->next;
    }
    printf("NULL \n");

}

void addNode(struct node **head, char* s)
{
    struct node* temp = malloc( sizeof(struct node) );
    temp->course= malloc(sizeof(char)*10);
    strcpy(temp->course, s);
    if(*head == NULL){
    temp->next = *head;
    *head=temp;
    }
    else{
    struct node* temp2;
    temp2= *head;
    while(temp2->next)
            temp2=temp2->next;
    temp->next=temp2->next;
    temp2->next=temp;
    }
}

void addlinkednode(struct linked **head,char* prereq)
{
    struct linked *temp = malloc( sizeof(struct linked) );
    temp->data= malloc(sizeof(char)*10);
    strcpy(temp->data, prereq);
    if(*head == NULL){
    temp->next = *head;
    *head=temp;
    }
    else{
    struct linked* temp2;
    temp2= *head;
    while(temp2->next)
            temp2=temp2->next;
    temp->next=temp2->next;
    temp2->next=temp;
  }
}
