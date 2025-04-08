#include <stdio.h>
#include "../queues/queue.h"
#include "../stacks/stack.h"
#include "reverse.h"


void Algorithm_Reverse_Queue_Using_Stack(Queue *queue, Stack *stack) {
    while (!Queue_IsEmpty(queue)) {
        int value = Queue_Dequeue(queue);
        Stack_Push(stack, value);
    }

    while (!Stack_IsEmpty(stack)) {
        int value = Stack_Pop(stack);
        Queue_Enqueue(queue, value);
    }
}
