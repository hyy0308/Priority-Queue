//
// Created by hyy on 10/26/2018.
//

#ifndef PRIORITY_QUEUE_PQUEUE_H
#define PRIORITY_QUEUE_PQUEUE_H
typedef struct {
    char name[16];
} DataNode;
typedef struct PQN {
    int priority;
    void *data;
    struct PQN *next;
} PQueueNode;
typedef struct {
    PQueueNode *head;
    PQueueNode *tail;
} PQueue;

int enqueue(PQueue *pqueue, int priority, void *data);
// put node in queue in priority order; in case of tie in priority,
// then put node after all nodes with the specified priority
void *dequeue(PQueue *pqueue);
// return NULL if queue is empty; otherwise return first node in queue
int printQueue(PQueue *pqueue);
// print queue from head to tail
void *peek(PQueue *pqueue);
// return the first node in the queue, but do not remove it; return NULL
// if queue is empty
int getMinPriority(PQueue *pqueue);
// return priority of first node in queue; return -1 if queue is empty


#endif //PRIORITY_QUEUE_PQUEUE_H
