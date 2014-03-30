// duplicate values for nodes ignored

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* newNode(int value);
void insert(Node *node, Node **head);
void printTree(Node *node);
Node* find(int value, Node *node);

//main function
int main(void) {
    Node *head = NULL;
    int i;
    // random seed
    srand(time(NULL));

    printf("\nInserting Values:\n");
    for (i = 0; i < 15; i++) {
        printf("\n%d:\t", i + 1);
        insert(newNode(rand() % 20 + 1), &head);
        printTree(head);
    }

    printf("\n\nFinding Values:\n");
    for (i = 0; i < 15; i++) {
        int number = rand() % 20 + 1;
        printf("\nFind %2d:\t", number);
        printTree(find(number, head));
    }
}

// creates and returns a new node
Node* newNode(int value) {
    Node *node;
    node = (Node *) malloc(sizeof(Node));

    node -> data = value;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

//inserts a value into a tree as a node
//inserts a value into a tree as a node
void insert(Node *node, Node **head) {
    Node *ptr = *head;

    // insert the node
    if (ptr == NULL) {                    // check if empty
        *head = node;
    } else {
        if ((node -> data) < (ptr -> data)) {
            insert(node, &(ptr -> left));
        } else if ((node -> data) > (ptr -> data)) {
            insert(node, &(ptr -> right));
        }
    }
}

// prints the tree using in-order notation
void printTree(Node *node) {
    if (node != NULL) {
        printTree(node -> left);
        printf("%d ", node -> data);
        printTree(node -> right);
    }
}

// returns node of value or NULL if it doesn't exist
Node* find(int value, Node *node) {
    if (node != NULL) {
        if ((node -> data) == value) {
            return node;
        } else if ((node -> data) > value) {
            return find(value, (node -> left));
        } else {
            return find(value, (node -> right));
        }
    }

    return NULL;
}
