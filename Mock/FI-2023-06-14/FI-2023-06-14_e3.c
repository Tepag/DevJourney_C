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
    char tmp;
    path[strlen(path)-1] = '\0'; // questa riga di codice mi riaggiusta la path che è qualcosa del genere: "./hotel1.txt" + '\n' + '\0', quindi metto uno \0 al posto di \n

    FILE* fpIn = fopen(path, "r");

    fgets(name, max, fpIn);
    
   
    do{
        fread(&tmp, sizeof(char), 1, fpIn);
        sumS += (float)(tmp-'0');
        cntS++;
        fread(&tmp, sizeof(char), 1, fpIn);
    }while(tmp!='\n');
    
    do{
        fread(&tmp, sizeof(char), 1, fpIn);
        sumPu += (float)(tmp-'0');
        cntPu++;
        fread(&tmp, sizeof(char), 1, fpIn);
    }while(tmp!='\n');

    do{
        fread(&tmp, sizeof(char), 1, fpIn);
        sumPo += (float)(tmp-'0');
        cntPo++;
        fread(&tmp, sizeof(char), 1, fpIn);
    }while(tmp!='\n');
    

    mediaS=sumS/cntS;
    mediaPu=sumPu/cntPu;
    mediaPo=sumPo/cntPo;

    fclose(fpIn);
    
    
    return (mediaS+mediaPo+mediaPu)/3;

}


hotel incubo(char* path, int max, int maxHotel){
    
    FILE* fpIn;
    fpIn = fopen(path, "r");
    hotel arr[maxHotel];
    int minI=0;
    int i=0;
    char hotelpath[max];
    int cnt;

    while(fgets(hotelpath, max, fpIn)!=NULL){
        arr[i].media = voto_hotel(hotelpath, arr[i].name, max);
        i++;
    }
    cnt=i;

    
    for(i=0;i<cnt;i++){
        if(arr[minI].media>arr[i].media){
            minI = i;
        }
    }


    return arr[minI];
}

