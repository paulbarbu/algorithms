/**
 * Calculate the levenshtein distance between two strings
 */
#include <stdio.h>
#include <string.h>

int d[100][100]; //change this if one of the strings is longer than 100 chars

int minimum_of_three(int x, int y, int z){
    if(x<y){
        y = x;
    }

    if(y<z){
        z = y;
    }

    return z;
}

int levenshtein_distance(char* a, char* b){
    int length_a = strlen(a), length_b = strlen(b);

    for(int i=0; i<length_a; i++){
        d[i][0] = i;
    }

    for(int i=0; i<length_b; i++){
        d[0][i] = i;
    }

    for(int i=1; i<length_a; i++){
        for(int j=1; j<length_b; j++){
            if(a[i] == b[j]){
                d[i][j] = d[i-1][j-1];
            }
            else{
                d[i][j] = 1 + minimum_of_three(d[i-1][j], d[i][j-1], d[i-1][j-1]);
            }
        }
    }

    return d[length_a-1][length_b-1];
}

int main(){
    char a[100], b[100], pa[100] = " ", pb[100] = " ";
    FILE *f;

    f = fopen("l.in", "r");

    fscanf(f, "%s %s", a, b);

    //need this in order to have the same starting point in both strings
    strcat(pa, a);
    strcat(pb, b);

    printf("%d\n",levenshtein_distance(pa, pb));

    fclose(f);
}
