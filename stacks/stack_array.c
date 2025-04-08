#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
    int top;
    int *values;
};

Stack * Stack_Create() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s != NULL) {
        s->top = -1;
        s->values = (int *)malloc(STACK_MAX * sizeof(int));
        if (s->values == NULL) {
            free(s);
            return NULL;
        }
    }
    return s;
}

void Stack_Destroy(Stack *s) {
    if (s != NULL) {
        free(s->values);
        free(s);
    }
}

bool Stack_IsEmpty(Stack *s) {
    return s->top == -1;
}

bool Stack_Push(Stack *s, int value) {
    if (s->top >= STACK_MAX - 1)
        return false; 
    s->top++;
    s->values[s->top] = value;
    return true;
}

int Stack_Pop(Stack *s) {
    if (Stack_IsEmpty(s)) {
        printf("Erro: Pilha vazia\n");
        return -1; 
    }
    return s->values[s->top--];
}

int Stack_Peek(Stack *stack) {
    if (Stack_IsEmpty(stack)) return -1;
    return stack->values[stack->top - 1];
}

