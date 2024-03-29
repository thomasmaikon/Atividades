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


void shell_sort(tDado dado[], int size){
    int metade = size/2;
    for(; metade > 0 ; metade = metade/2){
        for(int i=0; i+metade <= size ;++i){
            if (dado[i].id >= dado[i+metade].id){
                int buffer = dado[i].id;
                dado[i].id = dado[i+metade].id;
                dado[i+metade].id = buffer;
            }
        }
    }
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

    shell_sort(dado,5);

    printf("\nVetor Ordenado: ");
    for(int i = 0; i < 5; ++i){
        printf(" -> id:%d ",dado[i].id);
    }

}