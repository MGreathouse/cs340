#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int htoi(char hex[]);
int htod(char hex);


main() {
    char s[1000];

    int i = 1;
    int c, trk;

    trk = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        s[trk++] = c;
    }
    s[trk] = '\0';

    //q is my own quit variable
    while (i != 0) {
        i = htoi(s);

        if (i != 0) {
            s[0] = '\0';
            trk = 0;
            while ((c = getchar()) != '\n' && c != EOF) {
                s[trk++] = c;
            }
            s[trk] = '\0';
        }
    }
}


int htoi(char hex[]) {
    int i, len, total, ctr;
    ctr = 0;

    len = strlen(hex);

    if (len >=2 && (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))) {
        i = 2;
    } else {
        i = 0;
    }

    for(total = 0; len-1 >= i; len--) {
        if (isxdigit(hex[len-1])) {
            total += (htod(hex[len-1]) * pow(16, ctr++));
        } else {
            printf("Invalid Entry!\n");
            return 0;
        }
    }

    printf("%d\n", total);
    return 1;
}


int htod(char hex) {
    int val;

    switch (hex) {
        case '0':
            val = 0;
            break;
        case '1':
            val = 1;
            break;
        case '2':
            val = 2;
            break;
        case '3':
            val = 3;
            break;
        case '4':
            val = 4;
            break;
        case '5':
            val = 5;
            break;
        case '6':
            val = 6;
            break;
        case '7':
            val = 7;
            break;
        case '8':
            val = 8;
            break;
        case '9':
            val = 9;
            break;
        case 'a':
        case 'A':
            val = 10;
            break;
        case 'b':
        case 'B':
            val = 11;
            break;
        case 'c':
        case 'C':
            val = 12;
            break;
        case 'd':
        case 'D':
            val = 13;
            break;
        case 'e':
        case 'E':
            val = 14;
            break;
        case 'f':
        case 'F':
            val = 15;
            break;
    }

    //printf("Hex:\t%s\nVal:\t%d\n\n", hex, val);
    return val;
}
