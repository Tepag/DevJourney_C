
// Your code here
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 3
#define N 2

int check(int mat[][M], int n, int m){
    int i, j;
    int lastRecord=-1;
    int max=0;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]>mat[i][max]){
                max=j;
            }
        }

        //printf("\n%d > %d\n", max, lastRecord);
        if(max>lastRecord){
            lastRecord=max;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int main() {
    int matrix[N][M]={
        {1,0,0},
        {0,1,0}
    };
    
    printf("\n\n%d\n\n", check(matrix, N, M));
    printf("se 1 allora ha passato il test, se 0 allora no\n");

    return 0;
}
