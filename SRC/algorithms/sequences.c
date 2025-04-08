#include <stdlib.h>
#include <stdbool.h>
#include "sequences.h"
#include "../stacks/stack.h"

bool validateStackSequences(int* pushed, int* popped, int length) {
    Stack *stack = Stack_Create();
    if (stack == NULL) return false;

    int j = 0; // índice de popped

    for (int i = 0; i < length; i++) {
        Stack_Push(stack, pushed[i]);

        while (!Stack_IsEmpty(stack) && Stack_Peek(stack) == popped[j]) {
            Stack_Pop(stack);
            j++;
        }
    }

    bool result = Stack_IsEmpty(stack);
    Stack_Destroy(stack);
    return result;
}

bool Algorithm_Sequences_IsValid(int* pushed, int* popped, int size) {
    int *stack = (int *)malloc(size * sizeof(int));
    int top = -1;
    int popIndex = 0;

    for (int i = 0; i < size; ++i) {
        stack[++top] = pushed[i]; 
        while (top >= 0 && stack[top] == popped[popIndex]) {
            top--;    
            popIndex++;
        }
    }

    free(stack);
    return top == -1;
}
