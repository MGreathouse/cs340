#include <stdio.h>
#include <string.h>


// squeeze: deletes all characters in string1 that are also in string 2
void squeeze(char s1[], char s2[]);


int main() {
    // added in main to allow for a test
    char s1[] = "This is test 1!";
    char s2[] = "aeiou";
    squeeze(s1, s2);

    char s3[] = "This is test 2!";
    char s4[] = "T !";
    squeeze(s3, s4);

    return 0;
}


void squeeze(char s1[], char s2[]) {
    int i, j, k, tracker;

    for (i=k=0; i < strlen(s1); i++) {
        tracker = 0;
        for (j=0; j < strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                tracker = 1;
            }
        }

        if (!tracker) {
            s1[k++] = s1[i];
        }
    }

    s1[k] = '\0';

    // this is just display for testing purposes
    printf("%s\n", s1);
}
