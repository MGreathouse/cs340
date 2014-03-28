// duplicate values for nodes ignored

#include <stdio.h>
#include <string.h>

typedef struct node {
    int value;
    node *left, *right;
} Node;

void insert(int value, Node **head);
Node new(int value);
void printTree(Node *head);

//main function
int main(void) {
    Node *head;
    int i;

    for (i = 0; i < 10; i++) {
        //
    }
}

// creates and returns a new node
Node new(int value) {
    Node *node;

    node = (Node *) malloc(sizeof(Node));

    node -> value = value;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

//inserts a value into a tree as a node
void insert(int value, Node **head) {
    // get a new node based on value
    Node *node = new(value), *ptr = *head;
    bool notInserted = TRUE;

    // insert the node
    if (*ptr == NULL) {                     // check if empty
        *head = node;
    } else {
        while (ptr -> value != value && notInserted) {
            if (value < *head -> value) {   // if new value is less than current node
                if (ptr -> left == NULL) {
                    ptr -> left = node;
                    notInserted = FALSE;
                } else {
                    ptr = ptr -> left;
                }
            } else {                        // if new value is greater than current node
                if (ptr -> right == NULL) {
                    ptr -> right = node;
                    notInserted = FALSE;
                } else {
                    ptr = ptr -> right;
                }
            }
    }
}


//prints the tree
void printTree(Node *head) {
    printf("the tree");
}
