#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXHOTEL 50
#define MAX 50

typedef struct{
    char name[MAX];
    float media;
}hotel;

hotel incubo(char* path, int max, int maxHotel);
float voto_hotel(char* path, char* name, int max);

int main(int argc, char* argv[]) {
    hotel peggiore;
    
    peggiore = incubo(argv[1], MAX, MAXHOTEL);
    printf("il name del peggior hotel e\': %s", &(peggiore.name[0]));
    printf("\ncon la media di %.2f", peggiore.media);
    
    return 0;
}

float voto_hotel(char* path, char* name, int max){
    float mediaS, mediaPu, mediaPo;
    float sumS=0, sumPu=0, sumPo=0;
    float cntS=0, cntPu=0, cntPo=0;
    int iTmp;
    char tmp;
    FILE* fpIn = fopen(path, "r");

    char test[10];

    //fread(&tmp, sizeof(char), 1, fpIn);
    printf("\n\n%c\n\n", tmp);

    //fgets(test, max, fpIn);
    //puts(test);
    
    //fgets(name, max, fpIn);
    /*
    do{
        fread(&iTmp, sizeof(int), 1, fpIn);
        sumS += (float)iTmp;
        cntS++;
        fread(&tmp, sizeof(char), 1, fpIn);
    }while(tmp!='\n');

    do{
        fread(&iTmp, sizeof(int), 1, fpIn);
        sumPu += (float)iTmp;
        cntPu++;
        fread(&tmp, sizeof(char), 1, fpIn);
    }while(tmp!='\n');

    do{
        fread(&iTmp, sizeof(int), 1, fpIn);
        sumPo += (float)iTmp;
        cntPo++;
        fread(&tmp, sizeof(char), 1, fpIn);
    }while(tmp!='\n');
    

    mediaS=sumS/cntS;
    mediaPu=sumPu/cntPu;
    mediaPo=sumPo/cntPo;

    fclose(fpIn);
    
    */

    //return (mediaS+mediaPo+mediaPu)/3;

    return 0;

}


hotel incubo(char* path, int max, int maxHotel){
    
    FILE* fpIn;
    fpIn = fopen(path, "r");
    hotel arr[maxHotel];
    int minI=0;
    int i=0;
    char hotelpath[max];
    int cnt;

    fgets(hotelpath, max, fpIn);
    printf("\n\n%f\n\n", voto_hotel(hotelpath, arr[i].name, max));
    

    while(fgets(hotelpath, max, fpIn)!=NULL){
        printf("\n\n%s\n\n", hotelpath);
        /*
        arr[i].media = voto_hotel(&hotelpath[0], &(arr[i].name[0]), max);
        i++;
        */
    }
    cnt=i;

    /*
    for(i=0;i<cnt;i++){
        if(arr[minI].media>arr[i].media){
            minI = i;
        }
    }*/

    hotel test;
    test.media = 3.3;
    strcpy(test.name, "ciao");

    //return arr[minI];
    return test;
}

