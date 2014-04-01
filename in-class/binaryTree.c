// duplicate values for nodes ignored

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* newNode(int value);
void insert(Node *node, Node **head);
void printTreePre(Node *node);
void printTree(Node *node);
void printTreePost(Node *node);
Node* find(int value, Node *node);
void printMenu();
void respond(int uInput, Node **head);
int getInput();

//main function
int main(void) {
    Node *head = NULL;
    int uInput = -1;

    while (uInput) {
        printMenu();
        respond((uInput = getInput()), &head);
    }
    // // random seed
    // srand(time(NULL));

    // printf("\nInserting Values:\n");
    // for (i = 0; i < 15; i++) {
    //     printf("\n%d:\t", i + 1);
    //     insert(newNode(rand() % 20 + 1), &head);
    //     printTree(head);
    // }

    // printf("\n\nFinding Values:\n");
    // for (i = 0; i < 15; i++) {
    //     int number = rand() % 20 + 1;
    //     printf("\nFind %2d:\t", number);
    //     printTree(find(number, head));
    // }
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
void printTreePre(Node *node) {
    if (node != NULL) {
        printf("%d ", node -> data);
        printTreePre(node -> left);
        printTreePre(node -> right);
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

// prints the tree using in-order notation
void printTreePost(Node *node) {
    if (node != NULL) {
        printTreePost(node -> left);
        printTreePost(node -> right);
        printf("%d ", node -> data);
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

// Interface
// prints the menu
void printMenu() {
    printf("\nMenu:\n");
    printf("\t1:\t Add a new node\n");
    printf("\t2:\t Print preorder\n");
    printf("\t3:\t Print inorder\n");
    printf("\t4:\t Print postorder\n");
    printf("\t0:\t Quit\n");
    printf("\nChoose Task");
}

// responds to user input
void respond(int uInput, Node **head) {
    switch (uInput) {
        case 1:
            printf("New Value");
            insert(newNode(uInput = getInput()), head);
            printf("%d inserted.\n", uInput);
            break;
        case 2:
            printTreePre(*head);
            printf("\n");
            break;
        case 3:
            printTree(*head);
            printf("\n");
            break;
        case 4:
            printTreePost(*head);
            printf("\n");
            break;
        case 0:
            printf("Quitting...\n");
            break;
    }
}

// gets user input
int getInput() {
    int uInput;
    
    printf(" > ");
    scanf("%d", &uInput);
    printf("\n");

    return uInput;
}