#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// functions
void heapsort(int a[], int cnt);
void heapify(int a[], int cur, int max);

// main function
int main(void) {
    int cnt = 500000, a[cnt], i;

    srand(time(NULL));

    // create a random list
    for (i = 0; i < cnt; i++) {
        int r = rand();
        a[i] = r;
    }

    // print out list to show initial order
    // comment out this section to greatly reduce time
    clock_t start1 = clock();
    for (i = 0; i < cnt; i++) {
        printf("%d \t", a[i]);
    }
    printf("\n\n");
    clock_t end1 = clock();
    
    // the magic
    clock_t start2 = clock();
    heapsort(a, cnt);
    clock_t end2 = clock();

    // print out list to show initial order
    // comment out this section to greatly reduce time
    clock_t start3 = clock();
    for (i = 0; i < cnt; i++) {
        printf("%d \t", a[i]);
    }
    printf("\n\n");
    clock_t end3 = clock();

    printf("%.3f seconds to display initial list...\n", ((double)(end1 - start1) / CLOCKS_PER_SEC));
    printf("%.3f seconds to display sorted list...\n", ((double)(end3 - start3) / CLOCKS_PER_SEC));
    printf("%.3f seconds to sort %d integers \n", ((double)(end2 - start2) / CLOCKS_PER_SEC), cnt);

    return 0;
}

// heapsort
void heapsort(int a[], int cnt) {
    int i, tmp;

    // create an initial heap
    for (i = ((cnt - 1) / 2); i >= 0; i--) {
        heapify(a, i, cnt - 1);
    }

    // sort the heap
    for (i = cnt - 1; i >= 0; i--) {
        // swap the first value with the least unsorted value
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp; 

        // re-heap the rest of it
        heapify(a, 0, i - 1);
    }

}

// heapify
void heapify(int a[], int cur, int max) {
    if (cur * 2 + 1 <= max && a[cur] < a[cur * 2 + 1]) {
        if (cur * 2 + 2 <= max && a[cur * 2 + 1] < a[cur * 2 + 2]) {
            // left child is greater than the parent but not the right child
            //printf("%d > %d\t\tswapping right...\n", a[cur * 2 + 2], a[cur * 2 + 1]);
            
            // swap
            int i = a[cur];
            a[cur] = a[cur * 2 + 2];
            a[cur * 2 + 2] = i;

            // check to ensure still a heap
            heapify(a, cur * 2 + 2, max);
        } else {
            // the left child is greater than the parent and the right child if it exists
            //printf("%d > %d\t\tswapping left...\n", a[cur * 2 + 1], a[cur]);
            
            // swap
            int i = a[cur];
            a[cur] = a[cur * 2 + 1];
            a[cur * 2 + 1] = i;

            // check to ensure still a heap
            heapify(a, cur * 2 + 1, max);
        }
    } else if (cur * 2 + 2 <= max && a[cur] < a[cur * 2 + 2]) {
        // right child is greater than the parent
        //printf("%d > %d\t\tswapping right...\n", a[cur * 2 + 2], a[cur]);
        
        // swap
        int i = a[cur];
        a[cur] = a[cur * 2 + 2];
        a[cur * 2 + 2] = i;

        // check to ensure still a heap
        heapify(a, cur * 2 + 2, max);
    } else {
        //printf("Index %d heaped\n\n", cur);
    }
}