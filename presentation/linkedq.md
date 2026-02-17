# Linked Queue Presentation
## Part 1
- 2 byte int + 2 byte pointer = 4 byte node size 
- Node: the individual "link" in the chain. It holds a piece of data and a pointer to the next link
- Queue: the "manager" of the line. It tracks the front (where we remove items) and the rear (where we add items)

```
#define NODESIZE 4

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};
```

## Part 2
- create_queue: initializes an empty queue
- is_empty: checks if it is empty (necessary for insertion and removal)
```
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
```

## Part 3
- insert (enqueue): To add an item, the code asks for a new chunk of memory (alloc). It puts the new node at the rear of the line. If the line was empty, the front and rear both point to this new node.
- dequeue: This looks at the front node, grabs its value, and then moves the front pointer to the next node in line. It uses free(temp) to give the memory back to the system

```
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
```