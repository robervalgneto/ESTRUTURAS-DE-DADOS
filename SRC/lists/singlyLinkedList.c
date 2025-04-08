#include <stdlib.h>
#include "singlyLinkedList.h"

SinglyLinkedList * SinglyLinkedList_Create() {
    SinglyLinkedList * list = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
    if (list != NULL) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

void SinglyLinkedList_Destroy(SinglyLinkedList * list) {
    SinglyListNode * current = list->head;
    while (current != NULL) {
        SinglyListNode * temp = current;
        current = SinglyListNode_GetNext(current);
        SinglyListNode_Destroy(temp);
    }
    free(list);
}

bool SinglyLinkedList_IsEmpty(SinglyLinkedList * list) {
    return list->size == 0;
}

void SinglyLinkedList_AddFirst(SinglyLinkedList * list, int value) {
    SinglyListNode * node = SinglyListNode_Create(value, list->head);
    list->head = node;
    list->size++;
}

void SinglyLinkedList_AddLast(SinglyLinkedList * list, int value) {
    SinglyListNode * node = SinglyListNode_Create(value, NULL);
    if (list->head == NULL) {
        list->head = node;
    } else {
        SinglyListNode * current = list->head;
        while (SinglyListNode_GetNext(current) != NULL) {
            current = SinglyListNode_GetNext(current);
        }
        SinglyListNode_SetNext(current, node);
    }
    list->size++;
}

void SinglyLinkedList_Enqueue(SinglyLinkedList * list, int value) {
    SinglyLinkedList_AddLast(list, value);
}

int SinglyLinkedList_Dequeue(SinglyLinkedList * list) {
    if (list->head == NULL) return -1;

    SinglyListNode * node = list->head;
    int value = SinglyListNode_GetValue(node);
    list->head = SinglyListNode_GetNext(node);
    SinglyListNode_Destroy(node);
    list->size--;
    return value;
}

SinglyListNode * SinglyLinkedList_GetHead(SinglyLinkedList * list) {
    return list->head;
}

void SinglyLinkedList_SetHead(SinglyLinkedList * list, SinglyListNode * newHead) {
    list->head = newHead;
}

int SinglyLinkedList_GetSize(SinglyLinkedList * list) {
    return list->size;
}

SinglyListNode * SinglyLinkedList_Search(SinglyLinkedList * list, int value) {
    SinglyListNode * current = list->head;
    while (current != NULL) {
        if (SinglyListNode_GetValue(current) == value) return current;
        current = SinglyListNode_GetNext(current);
    }
    return NULL;
}

void SinglyLinkedList_Delete(SinglyLinkedList * list, SinglyListNode * nodeToDelete) {
    if (list->head == NULL || nodeToDelete == NULL) return;

    if (list->head == nodeToDelete) {
        list->head = SinglyListNode_GetNext(nodeToDelete);
        SinglyListNode_Destroy(nodeToDelete);
        list->size--;
        return;
    }

    SinglyListNode * current = list->head;
    while (current != NULL && SinglyListNode_GetNext(current) != nodeToDelete) {
        current = SinglyListNode_GetNext(current);
    }

    if (current != NULL) {
        SinglyListNode_SetNext(current, SinglyListNode_GetNext(nodeToDelete));
        SinglyListNode_Destroy(nodeToDelete);
        list->size--;
    }
}

int * SinglyLinkedList_ToArray(SinglyLinkedList * list) {
    if (list->size == 0) return NULL;

    int *array = (int *) malloc(sizeof(int) * list->size);
    SinglyListNode * current = list->head;
    int i = 0;

    while (current != NULL) {
        array[i++] = SinglyListNode_GetValue(current);
        current = SinglyListNode_GetNext(current);
    }

    return array;
}
