#include <stdio.h>

/* replaces input whitespace to only single instances at a time */
main() {
    int last, c;
    last = EOF;     // this will ensure uniqueness in the first iteration

    while ((c = getchar()) != EOF) {
        if (c == last) {
            if (c != ' ' && c != '\t' && c != '\n') {
                putchar(c);
            }
        } else if(c != last) {
            putchar(c);
        }

        last = c;
    }
}