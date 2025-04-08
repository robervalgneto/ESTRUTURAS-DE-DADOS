#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue {
    int head;
    int tail;
    int size;
    int *values;
};

Queue * Queue_Create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q != NULL) {
        q->head = 0;
        q->tail = 0;
        q->size = 0;
        q->values = (int *)malloc(QUEUE_MAX * sizeof(int));
        if (q->values == NULL) {
            free(q);
            return NULL;
        }
    }
    return q;
}

void Queue_Destroy(Queue *queue) {
    if (queue != NULL) {
        free(queue->values);
        free(queue);
    }
}

bool Queue_IsEmpty(Queue *queue) {
    return queue->size == 0;
}

bool Queue_Enqueue(Queue *queue, int value) {
    if (queue->size == QUEUE_MAX) {
        return false;
    }
    queue->values[queue->tail] = value;
    queue->tail = (queue->tail + 1) % QUEUE_MAX;
    queue->size++;
    return true;
}

int Queue_Dequeue(Queue *queue) {
    if (Queue_IsEmpty(queue)) {
        printf("Erro: Fila vazia\n");
        return -1;
    }
    int value = queue->values[queue->head];
    queue->head = (queue->head + 1) % QUEUE_MAX;
    queue->size--;
    return value;
}
