/*
    This file is to practice linked lists
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
}; typedef struct node listItem;

listItem* addNewNodeEnd(listItem * head, int newValue);
listItem* addNewNodeStart(listItem * head, int newValue);
listItem * addNewNodeIncreasing(listItem * head, int newValue);
listItem * addNewNodeDecreasing(listItem * head, int newValue);
listItem * reverseList(listItem * head);

listItem * insertFirst(listItem * head, listItem * newNode);
void insertAfter(listItem * node, listItem * newNode);
void printList(listItem * head);
int listLength(listItem * head);
void freeList(listItem * head);

int main() {

    listItem * head;
    int newValue;
    int choice = 1;
    int length = 1;

    head = NULL;

    while (length <= 5) {

        printf("Would you like to enter a new node?");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a new node: ");
            scanf("%d", &newValue);

            head = addNewNodeDecreasing(head, newValue);

            printList(head);
        }
        length = listLength(head);
    }

    printf("Reverse List:\n");

    head = reverseList(head);
    printList(head);

    printf("End of reverse list\n");
    
    freeList(head);

    return 0;
}

listItem* addNewNodeEnd(listItem * head, int newValue) {
    
    // listItem variable to store new node's value and next
    listItem * newNode;
    newNode = malloc(sizeof(listItem));

    // Sets values of newNode
    newNode->value = newValue;
    newNode->next = NULL;

    // Sets head to newValue if head is NULL
    if (head == NULL) {
        return newNode;
    }

    // Variable to iterate through linked list and locate last node
    listItem * temp;
    temp = head;
    
    // Locates end of linked list and sets pointer to new node 
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

listItem* addNewNodeStart(listItem * head, int newValue) {

    listItem * newNode;
    newNode = malloc(sizeof(listItem));

    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    listItem * temp = head;

    head = newNode;
    head->next = temp;

    return head;
}

listItem * addNewNodeIncreasing(listItem * head, int newValue) {

    // Declaring newNode
    listItem * newNode;
    newNode = malloc(sizeof(listItem));

    newNode->value = newValue;
    newNode->next = NULL;

    // Places newNode in first spot and returns
    if (head == NULL) {
        return newNode;
    }

    if (head->value > newValue) {
        head = insertFirst(head, newNode);
        return head;
    }

    // Declares temp variable that will iterate through starting at head
    listItem * temp;
    listItem * prev;
    temp = head;

    // While loop stops when temp is NULL or when temp->value > newValue
    while((temp != NULL) && (temp->value < newValue)) {
        prev = temp;
        temp = temp->next;
    }

    insertAfter(prev, newNode);
    newNode->next = temp;

    return head;
}

listItem * addNewNodeDecreasing(listItem * head, int newValue) {
    listItem * newNode;
    newNode = malloc(sizeof(listItem));

    newNode->value = newValue;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    if (head->value < newValue) {
        head = insertFirst(head, newNode);
        return head;
    }

    listItem * temp;
    listItem * prev;

    temp = head;
    
    while ((temp != NULL) && (temp->value > newValue)) {
        prev = temp;
        temp = temp->next;
    }

    insertAfter(prev, newNode);
    newNode->next = temp;

    return head;
}

listItem * reverseList(listItem * head) {

    listItem * prev;
    listItem * cur;
    listItem * after;

    if (head == NULL) {
        return head;
    }

    prev = NULL;
    cur = head;
    after = head->next;

    while(after != NULL) {
        cur->next = prev;

        prev = cur;
        cur = after;
        after = after->next; 
    }
    if (prev != NULL) {
        cur->next = prev;
    }

    return cur;
}

listItem * insertFirst(listItem * head, listItem * newNode) {
    newNode->next = head;
    return newNode;
}

void insertAfter(listItem * node, listItem * newNode) {
    
    listItem * temp;
    temp = node->next;

    node->next = newNode;
    newNode->next = temp;
}

void printList(listItem * head) {

    listItem * temp;
    temp = head;

    if (head == NULL) {
        printf("List contains no items.\n");
        return;
    }
    printf("\n");
    while (temp->next != NULL) {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("%d", temp->value);
    printf("\n\n");

    return; 
}

int listLength(listItem * head) {

    int i = 0;

    while (head != NULL) {
        head = head->next;
        i++;
    }

    return i;
}

void freeList(listItem * head) {

    listItem * temp;
    temp = head;

    while (head->next != NULL) { 
        temp = head;
        head = temp->next;
        free(temp);
    }
    free(head);
}

