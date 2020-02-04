#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[30];
}tDado;

void start(tDado* dado,int id,char nome[]){
    dado->id = id;
    strcpy(dado->nome,nome);
}


void quick_sort(tDado dado[], int size){
    
}

int main(){


    tDado dado[5];
 
    start(&dado[0],15,"pp");
    start(&dado[1],5,"ppo");
    start(&dado[2],1,"012p");
    start(&dado[3],19,"thomas");
    start(&dado[4],8,"pedro");

    printf("Vetor Inicial: ");
    for(int i=0;i<5;++i){
        printf(" -> id:%d ",dado[i].id);
    }

    quick_sort(dado,5);

    printf("\nVetor Ordenado: ");
    for(int i = 0; i < 5; ++i){
        printf(" -> id:%d ",dado[i].id);
    }

}