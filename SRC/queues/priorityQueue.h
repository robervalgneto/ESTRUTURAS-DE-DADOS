#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdbool.h>

typedef struct {
    int *array;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue * PriorityQueue_Create(); 
PriorityQueue * PriorityQueue_Create_WithCapacity(int capacity);

void PriorityQueue_Destroy(PriorityQueue *queue);
bool PriorityQueue_IsEmpty(PriorityQueue *queue);
void PriorityQueue_Enqueue(PriorityQueue *queue, int value);
int PriorityQueue_Dequeue(PriorityQueue *queue);

#endif

