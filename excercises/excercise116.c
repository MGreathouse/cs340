#include <stdio.h>
#define MAXLINE 1000  // maximum input line length

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main() {
    int len;                // current line length
    int max;                // maximum line length
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {  // a line existed
        printf("Length:%25d characters\nInput:\n%s\n", max, longest);
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

// copy:    copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[]) {
    int i;
    i = 0;

    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
