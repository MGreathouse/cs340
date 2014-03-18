#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void createNode(int value, Node **head, Node **tail);
void printNodes(Node *head);


int main(void) {
    Node *head = NULL, *tail = NULL;
    int i;

    int numbers[10];
    for(i = 0; i < 10; i++) {
        numbers[i] = i + 1;
    }

    for(i = 0; i < 10; i++) {
        createNode(numbers[i], &head, &tail);
    }

    printNodes(head);

    return 0;
}


void createNode(int value, Node **head, Node **tail) {
    Node *node;

    node = (Node *) malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;

    if(*tail != NULL) {
        (*tail) -> next = node;
    }
    
    *tail = node;

    if(*head == NULL) {
        *head = node;
    }
}

void printNodes(Node *head) {
    Node *ptr = head;

    while(ptr != NULL) {
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}
