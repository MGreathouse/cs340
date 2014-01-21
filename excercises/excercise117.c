#include <stdio.h>
#define MAXLINE 1000  // maximum input line length

int getLine(char line[], int maxline);

/* prints lines longer than 80 characters */
main() {
    int len;                // current line length
    char line[MAXLINE];     // current input line

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("%s", line);
        }
    }
    return 0;
}

// getLine:     read a line into line, returns length
int getLine(char line[], int maxline) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c !='\n'; i++) {
        if (i < maxline - 1) {
            line[i] = c;
        }
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}
