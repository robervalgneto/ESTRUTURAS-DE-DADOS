#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_MAX 100

typedef struct stack Stack;

Stack * Stack_Create();
void Stack_Destroy(Stack *);
bool Stack_IsEmpty(Stack *);
bool Stack_Push(Stack *, int value);
int Stack_Pop(Stack *);
int Stack_Peek(Stack *stack);


#endif
