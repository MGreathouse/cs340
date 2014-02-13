#include <stdio.h>
#include <string.h>


// any: finds and returns the first instance of a character form s2 in s1; defaults to -1 if nothing is found
int any(char s1[], char s2[]);


int main() {
    // added in main to allow for a test
    int i;

    char s1[] = "This is test 1!";
    char s2[] = "aeiou";
    i = any(s1, s2);

    char s3[] = "This is test 2!";
    char s4[] = "T !";
    i = any(s3, s4);

    char s5[] = "This shall be the longest test that I will do with this function simply because I can~";
    char s6[] = "zxy~";
    i = any(s5, s6);
}


int any(char s1[], char s2[]) {
    int i, j, pointer;

    pointer = -1;

    for (i = 0; s1[i] != '\0' && pointer == -1; i++) { // only need to loop through once each character
        for (j = 0; s2[j] != '\0' && pointer == -1; j++) { //will only loop until a match is found
            if (s1[i] == s2[j]) {
                pointer = i;
            }
        }
    }

    // this is just display for testing purposes
    printf("%d\n", pointer);

    return pointer;
}