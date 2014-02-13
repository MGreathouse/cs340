#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define JUMPERS 100


// store distance
typedef struct {
    int m, cm;
} Length;

// stores jumper and their record
typedef struct {
    Length dist;
    char name[255];
} Jump;

int totDist(Length l1);

int main() {
    int i, j;
    char inputName[] = "input.txt";
    FILE *fp = fopen(inputName, "r");
    
    Jump jumps[JUMPERS];
    int m, cm;
    char name[255];
    
    // prepare the jumpers
    for(i=0; i < JUMPERS; i++) {
        fscanf(fp, "%s %d %d", name, &m, &cm);
        
        Length ln;
        ln.m = m;
        ln.cm = cm;
        
        strcpy(jumps[i].name, name);
        jumps[i].dist = ln;
    }
    fclose(fp);
    
    // sort by best score
    for(i=1;i<JUMPERS;i++) {
        for(j=0;j<JUMPERS-i;j++) {
            if (totDist(jumps[j].dist) < totDist(jumps[j+1].dist)) {
                Jump holder = jumps[j];
                jumps[j] = jumps[j+1];
                jumps[j+1] = holder;
            }
        }
    }
    
    for(i=0; i < JUMPERS; i++) {
        printf("%d:\t%-15s\t%dm %02dcm\n", i+1, jumps[i].name, jumps[i].dist.m, jumps[i].dist.cm);
    }
    
    return 0;
}

int totDist(Length l1) {
    int cm;
    
    cm = l1.m * 100 + l1.cm;
    
    return cm;
}
