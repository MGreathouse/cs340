/*
    min, max, sum
*/


#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int value);
void insertAt(int value, Node **head, Node **tail, int loc);
void append(Node *node, Node **head, Node **tail);
int count(Node *head);
int pop(Node **head);
void printNodes(Node *head);
int min(Node *head);
int max(Node *head);
int sum(Node *head);


int main(void) {
    Node *head = NULL, *tail = NULL;
    int i;

    for(i = 0; i < 10; i++) {
        append(createNode(i+1), &head, &tail);
    }

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n", count(head));

    insertAt(11, &head, &tail, 5);

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n", count(head));

    insertAt(12, &head, &tail, 0);

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n", count(head));

    insertAt(13, &head, &tail, 15);

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n", count(head));

    insertAt(14, &head, &tail, 1);

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n", count(head));

    printf("\nYou popped: %d\n\n", pop(&head));

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n", count(head));

    printf("Min:\t%d\nMax:\t%d\nSum:\t%d\n", min(head), max(head, sum(head)));

    return 0;
}


Node* createNode(int value) {
    Node *node;

    node = (Node *) malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;

    return node;
}


void append(Node *node, Node **head, Node **tail) {
    if(*tail != NULL) {
        (*tail) -> next = node;
    }
    
    *tail = node;

    if(*head == NULL) {
        *head = node;
    }
}


void insertAt(int value, Node **head, Node **tail, int loc) {
    int cnt = count(*head);
    Node *node = createNode(value);

    if (cnt < loc || loc < 0) {
        append(node, head, tail);
    } else if (loc == 0) {
        node -> next = *head;
        *head = node;
    } else {
        Node *ptr = *head;

        while (--loc > 0) {
            ptr = ptr -> next;
        }

        node -> next = ptr -> next;
        ptr -> next = node;
    }
}


int count(Node *head) {
    Node *ptr = head;
    int cnt = 0;
    
    while (ptr != NULL) {
        cnt++;
        ptr = ptr -> next;
    }
    return cnt;
}


int pop(Node **head) {
    int val =  (*head) -> data; // will error out if empty list ~ don't care
    *head = (*head) -> next;
    
    return val;
}


void printNodes(Node *head) {
    Node *ptr = head;

    while(ptr != NULL) {
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}


int min(Node *head) {
    Node *ptr = head;
    int min;
    min = head -> data; // will error out if empty list ~ don't care

    while((ptr = ptr -> next) != NULL){
        if(ptr -> data < min) {
            min = ptr -> data;
        }
    }

    return min;
}


int max(Node *head) {
    Node *ptr = head;
    int max;
    max = head -> data; // will error out if empty list ~ don't care

    while((ptr = ptr -> next) != NULL){
        if(ptr -> data > max) {
            max = ptr -> data;
        }
    }

    
    return max;
}


int sum(Node *head) {
    Node *ptr = head;
    int sum = 0;
    
    while(ptr != NULL) {
        sum += ptr -> data;
        ptr = ptr -> next;
    }

    return sum;
}
