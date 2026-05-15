#include "BDSCTEST.h"
#include "finalque.c"

main()
{
    struct queue q;
    int v;

    START_TESTING("test_queue.c");

    TEST_CASE("create_queue initialises an empty queue");
        create_queue(&q);
        ASSERT(q.front == 0, "front is NULL after create");
        ASSERT(q.rear  == 0, "rear is NULL after create");


    TEST_CASE("is_empty returns true on a fresh queue");
        create_queue(&q);
        ASSERT(is_empty(&q), "queue is empty after create");


    TEST_CASE("is_empty returns false after one insert");
        create_queue(&q);
        insert(&q, 42);
        ASSERT(is_empty(&q) == 0, "queue is not empty after insert");


    TEST_CASE("insert one item: front and rear point to same node");
        create_queue(&q);
        insert(&q, 7);
        ASSERT(q.front != 0,       "front is non-NULL");
        ASSERT(q.rear  != 0,       "rear is non-NULL");
        ASSERT(q.front == q.rear,  "front == rear for single element");
        ASSERT(q.front->data == 7, "node holds correct value");


    TEST_CASE("insert two items: front != rear, correct data");
        create_queue(&q);
        insert(&q, 1);
        insert(&q, 2);
        ASSERT(q.front != q.rear,  "front != rear after two inserts");
        ASSERT(q.front->data == 1, "front holds first inserted value");
        ASSERT(q.rear->data  == 2, "rear holds second inserted value");


    TEST_CASE("dequeue returns values in FIFO order");
        create_queue(&q);
        insert(&q, 10);
        insert(&q, 20);
        insert(&q, 30);
        ASSERT(dequeue(&q) == 10, "first dequeue returns 10");
        ASSERT(dequeue(&q) == 20, "second dequeue returns 20");
        ASSERT(dequeue(&q) == 30, "third dequeue returns 30");

     
    TEST_CASE("dequeue on empty queue returns -1");
        create_queue(&q);
        ASSERT(dequeue(&q) == -1, "dequeue on empty queue returns -1");

     
    TEST_CASE("queue is empty after dequeuing all elements");
        create_queue(&q);
        insert(&q, 5);
        insert(&q, 6);
        dequeue(&q);
        dequeue(&q);
        ASSERT(is_empty(&q), "queue empty after draining all items");
        ASSERT(q.front == 0, "front is NULL after draining");
        ASSERT(q.rear  == 0, "rear is NULL after draining");

     
    TEST_CASE("front and rear correct after partial dequeue");
        create_queue(&q);
        insert(&q, 100);
        insert(&q, 200);
        insert(&q, 300);
        dequeue(&q);
        ASSERT(q.front->data == 200, "front advances to second element");
        ASSERT(q.rear->data  == 300, "rear still points to last element");

     
    TEST_CASE("insert after dequeue maintains correct order");
        create_queue(&q);
        insert(&q, 1);
        insert(&q, 2);
        dequeue(&q);
        insert(&q, 3);
        ASSERT(dequeue(&q) == 2, "next dequeue returns 2");
        ASSERT(dequeue(&q) == 3, "next dequeue returns 3");
        ASSERT(is_empty(&q),     "queue empty after all removed");

     
    TEST_CASE("zero value is stored and returned correctly");
        create_queue(&q);
        insert(&q, 0);
        ASSERT(is_empty(&q) == 0, "queue not empty after inserting 0");
        v = dequeue(&q);
        ASSERT(v == 0, "dequeue returns 0 correctly");

    END_TESTING();
}