#include <stdio.h>

/* counts blanks, tabs and newlines in input */
main() {
    int b, t, n, c;

    b = 0;
    t = 0;
    n = 0;

    while ((c = getchar()) != EOF) {
        // I missed these in Python, there is no other reason I am using it.
        switch (c){
            case (' '):
                b++;
                break;
            case ('\t'):
                t++;
                break;
            case ('\n'):
                n++;
                break;
        }
    }

    // displaying results
    printf("Blanks:\t\t%3d\n", b);
    printf("Tabs:\t\t%3d\n", t);
    printf("Newlines:\t%3d\n", n);
}