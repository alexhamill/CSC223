#include "stdio.h"

/* 2 byte int + 2 byte pointer = 4 byte node size */
#define NODESIZE 4

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

create_queue(q)
struct queue *q;
{
    q->front = 0;
    q->rear = 0;
}

is_empty(q)
struct queue *q;
{
    return (q->front == 0);
}

insert(q, val)
struct queue *q;
int val;
{
    struct node *new_node;

    new_node = alloc(NODESIZE);
    
    if (new_node == 0) {
        puts("Error: No memory!\n");
        return 0;
    }

    new_node->data = val;
    new_node->next = 0;

    if (q->rear == 0) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

dequeue(q)
struct queue *q;
{
    struct node *temp;
    int val;

    if (q->front == 0) {
        puts("Queue Empty!\n");
        return -1;
    }

    temp = q->front;
    val = temp->data;
    q->front = q->front->next;

    if (q->front == 0) {
        q->rear = 0;
    }

    free(temp);
    return val;
}

main()
{
    struct queue q;

    initw(0, 0);

    create_queue(&q);

    puts("Testing queue\n Inserting 1, 2, 3 to queue\n");

    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);

    printf("Dequeing first value: %d\n", dequeue(&q));
    
    printf("Inserting 4 to queue\n");

    insert(&q, 4);

    printf("Current queue: \n");
    
    while (!is_empty(&q)) {
        printf(" %d\n", dequeue(&q));
    }

}