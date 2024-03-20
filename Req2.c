#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// Stack definition and operations
typedef struct {
    int items[MAXSIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFullStack(Stack *s) {
    return s->top == MAXSIZE - 1;
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (!isFullStack(s)) {
        s->items[++s->top] = item;
    } else {
        printf("Stack is full\n");
    }
}

int pop(Stack *s) {
    if (!isEmptyStack(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack is empty\n");
        return -1; // Error code
    }
}

// Queue definition and operations
typedef struct {
    int items[MAXSIZE];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFullQueue(Queue *q) {
    return q->rear == MAXSIZE - 1;
}

int isEmptyQueue(Queue *q) {
    return q->rear == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int item) {
    if (!isFullQueue(q)) {
        if (isEmptyQueue(q)) q->front = 0;
        q->items[++q->rear] = item;
    } else {
        printf("Queue is full\n");
    }
}

int dequeue(Queue *q) {
    if (!isEmptyQueue(q)) {
        return q->items[q->front++];
    } else {
        printf("Queue is empty\n");
        return -1; // Error code
    }
}

// Singly linked list definition and operations
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = *head;
        *head = newNode;
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Instance Usage and implementation
int main() {
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    printf("Stack top after pushes: %d\n", pop(&s));

    Queue q;
    initQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    printf("Queue front after enqueues: %d\n", dequeue(&q));

    Node* head = NULL;
    insertAtFront(&head, 3);
    insertAtFront(&head, 4);
    printf("Linked List: ");
    displayList(head);

    return 0;
}


//Author : Taksha Sachin Thosani
//UTA ID: 1002086312
//Net ID : txt6312