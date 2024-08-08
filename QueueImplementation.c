#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL; // Fix to maintain proper queue behavior
    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode; // Move rear to the new node
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
}

void printQueue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* pointer = front;
    printf("Elements of Queue:\n");
    while (pointer) {
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    }
}

int main() {
    enqueue(32);
    enqueue(43);
    enqueue(98);
    enqueue(21);
    enqueue(3);

    printQueue();

    dequeue();

    printQueue();

    return 0;
}
