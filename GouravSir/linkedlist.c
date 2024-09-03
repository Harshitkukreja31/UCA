#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ListElement {
    int data;
    struct ListElement* next;
} ListElement;

typedef struct {
    ListElement* first;
    int count;
} LinkedList;

LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->first = NULL;
    list->count = 0;
    return list;
}

bool isListEmpty(LinkedList* list) {
    return list->count == 0;
}

int listSize(LinkedList* list) {
    return list->count;
}

void insertFront(LinkedList* list, int value) {
    ListElement* newElement = (ListElement*)malloc(sizeof(ListElement));
    newElement->data = value;
    newElement->next = list->first;
    list->first = newElement;
    list->count++;
}

int getElement(LinkedList* list, int position) {
    if (position < 0 || position >= list->count) return INT_MIN;
    
    ListElement* current = list->first;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->data;
}

int deleteElement(LinkedList* list, int position) {
    if (position < 0 || position >= list->count) return INT_MIN;
    
    ListElement* current = list->first;
    ListElement* previous = NULL;
    
    for (int i = 0; i < position; i++) {
        previous = current;
        current = current->next;
    }
    
    int removedData = current->data;
    
    if (previous == NULL) {
        list->first = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
    list->count--;
    return removedData;
}

void runTests() {
    LinkedList* myList = createList();
    
    insertFront(myList, 5);
    insertFront(myList, 15);
    insertFront(myList, 25);
    
    assert(!isListEmpty(myList));
    assert(listSize(myList) == 3);
    
    assert(getElement(myList, 0) == 25);
    assert(getElement(myList, 1) == 15);
    assert(getElement(myList, 2) == 5);
    
    assert(deleteElement(myList, 1) == 15);
    assert(listSize(myList) == 2);
    
    assert(getElement(myList, 0) == 25);
    assert(getElement(myList, 1) == 5);
    
    assert(deleteElement(myList, 0) == 25);
    assert(listSize(myList) == 1);
    
    assert(getElement(myList, 0) == 5);
    
    assert(deleteElement(myList, 0) == 5);
    assert(listSize(myList) == 0);
    
    assert(isListEmpty(myList));
    
    free(myList);
}

int main() {
    runTests();
    printf("All tests passed\n");
    return 0;
}