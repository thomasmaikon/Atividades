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

void select_sort(tDado dado[], int size){
    
    for(int j = 0; j < size; ++j){
        for(int i = 0; i < size;++i){
            if(dado[j].id < dado[i].id){
                int buffer = dado[j].id;
                dado[j].id = dado[i].id;
                dado[i].id = buffer;
            }
        }
    }
}

int main(){


    tDado dado[5];
 
    start(&dado[0],15,"pp");
    start(&dado[1],10,"ppo");
    start(&dado[2],1,"012p");
    start(&dado[3],19,"thomas");
    start(&dado[4],11,"pedro");

    printf("Vetor Inicial: ");
    for(int i=0;i < 5 ;++i){
        printf("-> id:%d ",dado[i].id);
    }

    select_sort(dado,5);

    printf("\nVetor Ordenado: ");
    for(int i = 0; i < 5; ++i){
        printf("-> id:%d  ",dado[i].id);
    }

}