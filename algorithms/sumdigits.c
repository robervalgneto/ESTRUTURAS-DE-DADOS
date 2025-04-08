#include <stdlib.h>
#include "../lists/singlyLinkedList.h"

SinglyLinkedList * Algorithm_SumDigits(SinglyLinkedList * listAddendOne, SinglyLinkedList * listAddendTwo) {
    SinglyListNode *node1 = listAddendOne->head;
    SinglyListNode *node2 = listAddendTwo->head;

    SinglyLinkedList *result = SinglyLinkedList_Create();
    int carry = 0;

    while (node1 != NULL || node2 != NULL || carry > 0) {
        int value1 = (node1 != NULL) ? node1->value : 0;
        int value2 = (node2 != NULL) ? node2->value : 0;
        int sum = value1 + value2 + carry;

        carry = sum / 10;
        int digit = sum % 10;

        SinglyLinkedList_AddLast(result, digit);

        if (node1 != NULL) node1 = node1->next;
        if (node2 != NULL) node2 = node2->next;
    }

    return result;
}
