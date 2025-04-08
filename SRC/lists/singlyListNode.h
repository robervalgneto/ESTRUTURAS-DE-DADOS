#ifndef SINGLY_LIST_NODE_H
#define SINGLY_LIST_NODE_H

typedef struct singlyListNode {
    int value;
    struct singlyListNode *next;
} SinglyListNode;

SinglyListNode * SinglyListNode_Create(int value, SinglyListNode * next);
void SinglyListNode_Destroy(SinglyListNode * node);
SinglyListNode * SinglyListNode_GetNext(SinglyListNode * node);
void SinglyListNode_SetNext(SinglyListNode * node, SinglyListNode * next);
int SinglyListNode_GetValue(SinglyListNode * node);
void SinglyListNode_SetValue(SinglyListNode * node, int value);

#endif
