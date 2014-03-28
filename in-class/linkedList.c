#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int value);
void sortedInsert(int value, Node **head, Node **tail);
void insertAt(int value, Node **head, Node **tail, int loc);
int removeAt(Node **head, Node **tail, int loc);
void append(Node *node, Node **head, Node **tail);
void sort(Node **head, Node **tail);
int count(Node *head);
int pop(Node **head);
void printNodes(Node *head);
int min(Node *head);
int max(Node *head);
int sum(Node *head);
int getIndex(Node *head, int ndx);


int main(void) {
    Node *head = NULL, *tail = NULL;
    int i;

    for(i = 0; i < 10; i++) {
        append(createNode(10-i), &head, &tail);
    }

    insertAt(11, &head, &tail, 5);
    insertAt(12, &head, &tail, 0);
    insertAt(13, &head, &tail, 15);
    insertAt(15, &head, &tail, 8);
    insertAt(16, &head, &tail, 7);
    sortedInsert(14, &head, &tail);

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n\n", count(head));

    sort(&head, &tail);

    printNodes(head);
    printf("\nThere are %d Nodes in this linked list.\n\n", count(head));

    return 0;
}

// creates and returns a node
Node* createNode(int value) {
    Node *node;

    node = (Node *) malloc(sizeof(Node));
    node -> data = value;
    node -> next = NULL;

    return node;
}

// adds a node
void append(Node *node, Node **head, Node **tail) {
    if (*tail != NULL) {
        (*tail) -> next = node;
    }
    
    *tail = node;

    if (*head == NULL) {
        *head = node;
    }
}

// adds a new node at a location where it should go assuming the list is sorted
void sortedInsert(int value, Node **head, Node **tail) {
    Node *ptr = *head;
    int loc = 0;

    if (*head == NULL) {
        append(createNode(value), head, tail);
    } else {
        if (ptr -> data > value) {
            insertAt(value, head, tail, 0);
        } else {
            while (ptr -> next != NULL && (ptr -> next) -> data < value) {
                ptr = ptr -> next;
                loc++;
            }

            // check to see if we are simply at the end or if we are where we need to be
            if (ptr -> next == NULL) {
                append(createNode(value), head, tail);
            } else {
                insertAt(value, head, tail, ++loc);
            }
        }
    }
}

// adds a new node at a specific location
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

// adds a new node at a specific location
int removeAt(Node **head, Node **tail, int loc) {
    int cnt = count(*head), val, i = 0;
    Node *ptr = *head;

    if (cnt -1 < loc) {
        loc = cnt - 1;
    } else if (loc < 0) {
        loc = 0;
    }

    if (loc == 0) {
        return pop(head);
    } else {
        while (ptr -> next != NULL && i < loc - 1) {
            i++;
            ptr = ptr -> next;
        }
        val = (ptr -> next) -> data;
        ptr -> next = (ptr -> next) -> next;
    }

    return val;
}

// sorts the list in place
void sort(Node **head, Node **tail) {
    int cnt = count(*head), i, j;
    Node *ptr = *head, *ptrN = *head;

    ptrN = ptrN -> next;

    for (i = 0; i < cnt - 1; i++) {
        for (j = 0; j < cnt - 1;  j++){
            if (ptr -> data > ptrN -> data) {
                sortedInsert(removeAt(head, tail, j), head, tail);
            }
            ptr = ptr -> next;
            ptrN = ptrN -> next;
        }
        ptr = *head;
        ptrN = ptr -> next;
    }
}

// returns the number of nodes
int count(Node *head) {
    Node *ptr = head;
    int cnt = 0;
    
    while (ptr != NULL) {
        cnt++;
        ptr = ptr -> next;
    }
    return cnt;
}

// removes the first node
int pop(Node **head) {
    int val =  (*head) -> data; // will error out if empty list ~ don't care
    *head = (*head) -> next;
    
    return val;
}

// displays the nodes
void printNodes(Node *head) {
    Node *ptr = head;

    while (ptr != NULL) {
        printf("%d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

// returns the lowest value in all the  nodes
int min(Node *head) {
    Node *ptr = head;
    int min;
    min = head -> data; // will error out if empty list ~ don't care

    while((ptr = ptr -> next) != NULL){
        if (ptr -> data < min) {
            min = ptr -> data;
        }
    }

    return min;
}

// returns the highest value node
int max(Node *head) {
    Node *ptr = head;
    int max;
    max = head -> data; // will error out if empty list ~ don't care

    while((ptr = ptr -> next) != NULL){
        if (ptr -> data > max) {
            max = ptr -> data;
        }
    }

    
    return max;
}

// returns the sum of the values in eah node
int sum(Node *head) {
    Node *ptr = head;
    int sum = 0;
    
    while (ptr != NULL) {
        sum += ptr -> data;
        ptr = ptr -> next;
    }

    return sum;
}

// returns the value at a specific index
int getIndex(Node *head, int ndx) {
    Node *ptr = head;
    int cnt = 0, lim = count(head) - 1;

    // this will get us around any size related issues (if the index is negative or too large)
    if (ndx < 0) {
        ndx = 0;
    } else if (ndx > lim) {
        ndx = lim;
    }

    while (ptr != NULL && cnt < ndx) {
        ptr = ptr -> next;
        cnt++;
    }

    return ptr -> data;
}
