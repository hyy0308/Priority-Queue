#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.h"
//push
int enqueue(PQueue *pqueue, int priority, void *data){
    PQueueNode* newNode =  (PQueueNode *) malloc(sizeof(PQueueNode));
    newNode->data = data;
    newNode->priority = priority;
    PQueueNode* current;
    if (pqueue->head == NULL || pqueue->head->priority > newNode->priority)
    {
        newNode->next = pqueue->head;
        pqueue->head = newNode;
    }
    else {
        current = pqueue->head;
        while (current->next!=NULL &&
               current->next->priority <= newNode->priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    return 0;
};
//pop
void *dequeue(PQueue *pqueue){
    if (pqueue->head == NULL) {
        return NULL;
    }
    DataNode* item = pqueue->head->data;
    pqueue->head = pqueue->head->next;
    return item;
};
int printQueue(PQueue *pqueue){
    PQueueNode* newNode = pqueue->head;
    while(newNode!=NULL){
        printf(newNode->data);
        printf("\n");
        newNode= newNode->next;
    }
    return 0;
};
void *peek(PQueue *pqueue){
    if(pqueue->head == NULL){
        return NULL;
    }else{
        DataNode* item = pqueue->head->data;
        return item;
    }
};
// return priority of first node in queue; return -1 if queue is empty
int getMinPriority(PQueue *pqueue){
    if(pqueue->head == NULL){
        return -1;
    }else{
        return pqueue->head->priority;
    }
};



int main() {
    printf("Hello, World!\n");
    return 0;
}