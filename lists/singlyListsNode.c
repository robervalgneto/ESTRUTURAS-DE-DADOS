#include <stdlib.h>
#include "singlyListNode.h"

SinglyListNode * SinglyListNode_Create(int value, SinglyListNode * next) {
    SinglyListNode * node = (SinglyListNode *) malloc(sizeof(SinglyListNode));
    if (node != NULL) {
        node->value = value;
        node->next = next;
    }
    return node;
}

void SinglyListNode_Destroy(SinglyListNode * node) {
    if (node != NULL) {
        free(node);
    }
}

SinglyListNode * SinglyListNode_GetNext(SinglyListNode * node) {
    return node ? node->next : NULL;
}

void SinglyListNode_SetNext(SinglyListNode * node, SinglyListNode * next) {
    if (node != NULL) {
        node->next = next;
    }
}

int SinglyListNode_GetValue(SinglyListNode * node) {
    return node ? node->value : -1;
}

void SinglyListNode_SetValue(SinglyListNode * node, int value) {
    if (node != NULL) {
        node->value = value;
    }
}
