#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// store the artists and their order
typedef struct artist {
    unsigned long votes;
    char name[255];
} Artist;


int main() {
    Artist artists[10];
    int i,j;
    char name[255];
    char inputName[] = "votes.txt";
    char outputName[] = "results.txt";
    FILE *fp = fopen(inputName, "r");

    // prepare artists
    for(i = 0; i < 10; i++) {
        fscanf(fp, "%s", name);
        strcpy(artists[i].name , name);
        artists[i].votes = 0;
    }
    
    // get votes
    int vote, v;
    vote = fscanf(fp, "%d", &v);
    while(v != 0) {
        artists[v-1].votes++;
        vote = fscanf(fp, "%d", &v);
    }
    fclose(fp);
  
    // figure results: alpha
    for(i=0;i<10;i++) {
        for(j=0;j<10-i;j++) {
            if (strcmp(artists[j].name, artists[j+1].name) > 0) {
                Artist holder = artists[j];
                artists[j] = artists[j+1];
                artists[j+1] = holder;
            }
        }
    }

    fp = fopen(outputName, "w");
    for(i=0; i < 10; i++){
        fprintf(fp, "%s\n\tVotes:  %d\n\n", artists[i].name, artists[i].votes);
    }
    fprintf(fp, "\n--------------------------------------------\n\n");

    // figure results: votes
    for(i=1;i<10;i++) {
        for(j=0;j<10-i;j++) {
            if (artists[j].votes < artists[j+1].votes) {
                Artist holder = artists[j];
                artists[j] = artists[j+1];
                artists[j+1] = holder;
            }
        }
    }

    for(i=0; i < 10; i++){
        fprintf(fp, "%s\n\tVotes:  %d\n\n", artists[i].name, artists[i].votes);
    }
    fclose(fp);
    return 0;
}
