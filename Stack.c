    #include<stdio.h>
    #include<stdlib.h>

    typedef struct Node
    {
        int data;
        struct Node* next;
    }Node;

    struct Node* top=NULL;

    int size=0;

    void pushNode(int value)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        if(newnode)
        {
        newnode->data=value;
        newnode->next=top;
        top=newnode;
        size++;
        }
        else printf("Oops! Insufficient Heap Memory... Stack Overflow Condition \n");
    }

    void popNode()
    {
        struct Node* temp=top;
        if(top)
        {
        printf("Popped Element is : %d\n", top->data);
        top=top->next;
        free(temp);
        size--;
        }
        else printf("Oops! Stack is Empty... Stack Underflow Condition \n");
    }

    void printStack()
    {
        struct Node* head=top;
        printf("Elements of the stack : \n");
        while(head)
        {
        printf("%d  \n", head->data);
        head=head->next;
        }
    }

    void peekNode()
    {
        printf("Top of Stack is : %d\n",top->data);
    }

    void sizeOfStack()
    {
        printf("Size of stack is : %d\n", size);
    }

    void main()
    {
        pushNode(10);
        pushNode(67);
        pushNode(34);

        peekNode();

        pushNode(9);
        pushNode(21);

        printStack();

        popNode();

        peekNode();

        printStack();

        sizeOfStack();
    }
