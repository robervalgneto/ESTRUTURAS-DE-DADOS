#include <stdlib.h>
#include <stdbool.h>
#include "priorityQueue.h"

int findLocation(PriorityQueue *queue, int value);
void openSpace(PriorityQueue *queue, int location);

PriorityQueue * PriorityQueue_Create() {
    return PriorityQueue_Create_WithCapacity(10); // Valor padrão
}

PriorityQueue * PriorityQueue_Create_WithCapacity(int capacity) {
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (queue == NULL) return NULL;

    queue->array = (int *)malloc(sizeof(int) * capacity);
    if (queue->array == NULL) {
        free(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

void PriorityQueue_Destroy(PriorityQueue *queue) {
    if (queue) {
        free(queue->array);
        free(queue);
    }
}

bool PriorityQueue_IsEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

int findLocation(PriorityQueue *queue, int value) {
    int i = 0;
    while (i < queue->size && queue->array[i] < value) {
        i++;
    }
    return i;
}

void openSpace(PriorityQueue *queue, int location) {
    for (int i = queue->size; i > location; i--) {
        queue->array[i] = queue->array[i - 1];
    }
}

void PriorityQueue_Enqueue(PriorityQueue *queue, int value) {
    if (queue->size >= queue->capacity) return;

    int loc = findLocation(queue, value);
    openSpace(queue, loc);
    queue->array[loc] = value;
    queue->size++;
}

int PriorityQueue_Dequeue(PriorityQueue *queue) {
    if (queue->size == 0) return -1;

    int value = queue->array[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->array[i] = queue->array[i + 1];
    }
    queue->size--;
    return value;
}
