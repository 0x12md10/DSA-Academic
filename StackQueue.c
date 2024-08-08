#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

struct Node* top=NULL;

void pushNode(int value)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node))
    newnode->data=value;
    newnode->next=top;
    top=newnode;
}

void printStack()
{
    struct Node* head=top;
    while(head)
    {
    printf("Elements of the stack : /n");
    printf("%d  ", head->data);
    head=head->next;
    }
}

void popNode()
{
    printf("Popped Element is : %d", top->data);
    top=top->next;
}

void main()
{
    pushNode(10);
    pushNode(67);
    pushNode(34);
    pushNode(9);
    pushNode(21);

    printStack();

    popNode();
}