#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../stacks/stack.h"

const char openers[] = "({[";
const char closers[] = ")}]";

bool isOpen(char character) {
    for (int i = 0; i < 3; i++) {
        if (character == openers[i]) return true;
    }
    return false;
}

char getOpen(char closeCharacter) {
    for (int i = 0; i < 3; i++) {
        if (closeCharacter == closers[i]) return openers[i];
    }
    return '\0';
}

bool Algorithm_Parenthesis_IsValid(char *expression) {
    Stack *stack = Stack_Create();
    if (stack == NULL) return false;

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isOpen(ch)) {
            Stack_Push(stack, ch); 
        } else {
            if (Stack_IsEmpty(stack)) {
                Stack_Destroy(stack);
                return false;
            }

            char top = Stack_Pop(stack);
            if (top != getOpen(ch)) {
                Stack_Destroy(stack);
                return false;
            }
        }
    }

    bool valid = Stack_IsEmpty(stack);
    Stack_Destroy(stack);
    return valid;
}
