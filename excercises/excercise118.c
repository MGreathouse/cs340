#include <stdio.h>
#include <string.h>
#define MAXLINE 1000  // maximum input line length

int getLine(char line[], int maxline);
int trimLine(char line[]);

/* print input lines without trailing whitespace */
main() {
    int len;                // current line length
    char line[MAXLINE];     // current input line

    while ((len = getLine(line, MAXLINE)) > 0) {
        len -= trimLine(line);
        line[len] = '\0';

        if (len > 0) {
            printf("%s\n", line);
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

//trimLine:     trims trailing white space
int trimLine(char line[]) {
    int cut, i;
    cut = 0;

    for (i = (strlen(line) - 1); i >= 0; i--) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\b' && line[i] != '\n') {
            break;
        } else {
            cut++;
        }
    }

    return cut;
}
