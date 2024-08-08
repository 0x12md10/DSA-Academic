#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    if(newNode) {
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        printf("%d pushed into the stack.\n", data);
    } else {
        printf("Stack overflow... no available memory\n");
    }
}

void pop() {
    if(!top) {
        printf("Stack is empty... stack underflow.\n");
        return;
    }
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    if(!temp) {
        printf("No available memory to create a temp.\n");
        return;
    }

    temp = top;

    top = top->next;
    printf("%d popped from the stack.\n",temp->data);
    free(temp);
}

void peek() {
    if(top) {
        printf("top of the stack is: %d\n",top->data);
    } else {
        printf("Stack is empty.\n");
    }
    
}

void display() {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head = top;
    if(!head) {
        printf("Stack is empty.\n");
        return;
    }

    while(head) {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
    free(head);
}

void main() {

    push(1);
    push(2);
    push(3);

    display();

    pop();
    pop();
    pop();
    pop();
    display();

}