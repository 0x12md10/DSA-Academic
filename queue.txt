#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(!newNode) {
        printf("Cannot create memory space for newNode\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    printf("%d is queued.\n",newNode->data);
    if(front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}


void dequeue() {
    if(front == NULL && rear == NULL) {
        printf("Queue is empty.. No items to display.\n");
        return;
    }
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    if(!temp) {
        printf("Cannot create memory space for temp\n");
        return;
    }
    temp = front;
    front = front->next;
    printf("%d dequeued.\n",temp->data);
    free(temp);
}

void display() {
 
    if(front == NULL && rear == NULL) {
        printf("Queue is empty.. No items to display.\n");
        return;
    }
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    if(!temp) {
        printf("Cannot create memory space for temp\n");
        return;
    }
    temp = front;
    
    while(temp) {
        printf("%d ",temp->data);
        temp =temp->next;
    }
    printf("\n");
}

void peek() {
    if(front == NULL && rear == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("%d is at the front of the queue.\n" , front->data);
    }
}

void main() {
    display();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    peek();
    dequeue();
    dequeue();
    peek();
    dequeue();
    display();
}