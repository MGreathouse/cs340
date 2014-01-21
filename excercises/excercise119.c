#include <stdio.h>
#include <string.h>
#define MAXLINE 1000  // maximum input line length

int getLine(char line[], int maxline);
void reverse(char s[]);

/* prints lines back in reverse */
main() {
    int len;                // current line length
    char line[MAXLINE];     // current input line

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 0) {
            reverse(line);
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

// reverse:     reverses a string and displays it
void reverse(char s[]) {
    int i, j;
    j = strlen(s);

    for (i = j - 2; i >= 0; i--) {      // remove 2 to get rid of extra newline
        putchar(s[i]);
    };
    putchar('\n');
}
