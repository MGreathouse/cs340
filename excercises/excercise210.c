#include <stdio.h>


char lower(char c);


int main() {
     putchar(lower('A'));
     putchar('\n');
     putchar(lower('S'));
     putchar('\n');
     putchar(lower('C'));
     putchar('\n');
     putchar(lower('Z'));
     putchar('\n');
     putchar(lower('I'));
     putchar('\n');

     return 0;
}


char lower(char c) {
    char c2;

    c2 = (c>='A' && c<='Z') ? c+ 'a'-'A' : c;

    return c2;
}
