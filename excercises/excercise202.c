#include <stdio.h>

#define MAXLIMIT 15;

// using this function to chect the next character and validating it there to meet requirments.
int nextChar(void);

main() {
    int i, c, lim;

    lim = MAXLIMIT;

    char s[lim];

    /*for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }*/

    // This is the new version without && or || in the for loop
    for (i = 0; i < lim - 1; ++i) {
        s[i] = nextChar();
    }

    printf(s);
}


int nextChar() {
    int c;

    c = getchar();

    while (c == '\n' || c == EOF) {
        c = getchar();
    }

    return c;
}
